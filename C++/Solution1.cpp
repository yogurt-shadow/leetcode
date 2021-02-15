#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> index;
        for(int i = 0; i < nums.size(); i++){
            int other = target - nums[i];
            if(index.count(other) > 0){
                return {i, index[other]};
            }
            index[nums[i]] = i;
        }
        return {-1, -1};
    }
};

int main(){
    Solution1 solution;
    vector<int> a = {2, 7, 11, 15};
    vector<int> result = solution.twoSum(a, 9);
    for(auto& ele: result){
        cout << ele << endl;
    }
    return 0;
}