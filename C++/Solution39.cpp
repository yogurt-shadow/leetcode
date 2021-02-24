#include<iostream>
#include<vector>

#include<algorithm>
using namespace std;

class Solution39 {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> dp;
        vector<int> combine;
        fill(dp, combine, candidates, target, 0, 0);
        return dp;
    }

    void fill(vector<vector<int>>& dp, vector<int>& combine, vector<int>& candidates, int target, int index, int sum){
        if(sum == target){
            dp.push_back(combine);
            return;
        }
        if(sum > target){
            return;
        }
        for(int i = index; i < candidates.size(); i++){
            combine.push_back(candidates[i]);
            fill(dp, combine, candidates, target, i, sum + candidates[i]);
            combine.pop_back();
        }
    }
};