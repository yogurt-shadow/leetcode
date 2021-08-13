#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

class Solution581 {
public:
    int findUnsortedSubarray(vector<int> &nums) {
        int left = -1, right = -1;
        int m1 = nums[nums.size() - 1], m2 = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] >= m2){
                m2 = nums[i];
            }
            else{
                right = i;
            }
            if (nums[nums.size() - 1 - i] <= m1){
                m1 = nums[nums.size() - 1 - i];
            }
            else{
                left = nums.size() - 1 - i;
            }
        }
        return right == -1 ? 0 : right - left + 1;
    }
};

int main(){
    vector<int> test = {2, 2};
    Solution581 s;
    cout << s.findUnsortedSubarray(test);
    return 0;
}