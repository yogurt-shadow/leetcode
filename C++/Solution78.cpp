#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<stack>
using namespace std;

class Solution78 {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int size = nums.size();
        for(int i = 0; i < (1 << size); i++){
            vector<int> store;
            for(int k = 0; k < size; k++){
                if((1 << k) & i){
                    store.push_back(nums[k]);
                }
            }
            res.push_back(store);
        }
        return res;
    }
};