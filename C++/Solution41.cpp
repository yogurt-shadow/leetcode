#include<iostream>
#include<vector>

#include<algorithm>
using namespace std;

class Solution41 {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            while(nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1]){
                int temp = nums[nums[i] - 1];
                nums[nums[i] - 1] = nums[i];
                nums[i] = temp;
            }
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != i + 1){
                return i + 1;
            }
        }
        return nums.size() + 1;
    }
};

int main(){
    vector<int> test = {1, 1};
    Solution41 s;
    cout << s.firstMissingPositive(test);
    return 0;
}