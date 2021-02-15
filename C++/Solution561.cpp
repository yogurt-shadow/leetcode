#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

class Solution561 {
public:
    int arrayPairSum(vector<int>& nums) {
        int sum = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i += 2){
            sum += nums[i];
        }
        return sum;
    }
};

int main(){
    Solution561 s;
    vector<int> test = {6,2,6,5,1,2};
    cout << s.arrayPairSum(test);
    return 0;
}