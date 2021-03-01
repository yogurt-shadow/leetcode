#include<iostream>
#include<vector>

#include<unordered_set>

using namespace std;

class Solution46 {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> store;
        unordered_set<int> set;
        fill(result, store, nums, 0, set);
        return result;
    }

    void fill(vector<vector<int>>& result, vector<int>& store, vector<int>& nums, int cur, unordered_set<int>& set){
        if(cur == nums.size()){
            result.push_back(store);
            return;
        }
        auto copy = set;
        for(int index = 0; index < nums.size(); index++){
            if(set.count(index) == 0){
                store.push_back(nums[index]);
                set.insert(index);
                fill(result, store, nums, cur + 1, set);
                set = copy;
                store.pop_back();
            }
        }
    }
};