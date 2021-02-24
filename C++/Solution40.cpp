#include<iostream>
#include<vector>

#include<algorithm>
using namespace std;

class Solution40 {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> dp;
        vector<int> combine;
        fill(dp, combine, candidates, target, -1, 0);
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
        for(int i = index + 1; i < candidates.size(); i++){
            combine.push_back(candidates[i]);
            fill(dp, combine, candidates, target, i, sum + candidates[i]);
            combine.pop_back();
            i++;
            while(i < candidates.size() && candidates[i] == candidates[i - 1]){
                i++;
            }
            i--;
        }
    }
};

int main(){
    vector<int> test = {10,1,2,7,6,1,5};
    Solution40 s;
    s.combinationSum2(test, 8);
    return 0;
}