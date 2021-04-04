#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Solution90 {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> store;
        dfs(false, res, store, nums, 0);
        return res;
    }

    void dfs(bool chosen, vector<vector<int>>& res, vector<int>& store, vector<int>& nums, int index){
        if(index == nums.size()){
            res.push_back(store);
            return;
        }
        dfs(false, res, store, nums, index + 1);
        if(index >= 1 && nums[index] == nums[index - 1] && !chosen){
            return;
        }
        store.push_back(nums[index]);
        dfs(true, res, store, nums, index + 1);
        store.pop_back();
    }
};