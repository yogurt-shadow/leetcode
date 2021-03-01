#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution47 {
public:
    vector<int> choose;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int size = nums.size();
        choose.resize(size);
        vector<vector<int>> res;
        vector<int> store;
        sort(nums.begin(), nums.end());
        fill(res, store, nums, 0);
        return res;
    }

    void fill(vector<vector<int>>& res, vector<int>& store, vector<int>& nums, int index)
{
    if(index == nums.size()){
        res.push_back(store);
        return;
    }
    for(int i = 0; i < nums.size(); i++){
        if(choose[i]){
            continue;
        }
        if(i > 0 && nums[i - 1] == nums[i] && choose[i - 1] == 0){
            continue;
        }
        choose[i] = 1;
        store.push_back(nums[i]);
        fill(res, store, nums, index + 1);
        store.pop_back();
        choose[i] = 0;
    }
}
};