#include<iostream>
#include<vector>
#include<queue>

using namespace std;
typedef pair<int, int> pii;

class Solution1470 {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int size = nums.size() / 2;
        vector<int> ans(size * 2);
        for(int i = 0; i < size * 2; i++){
            if(i % 2 == 0){
                ans[i] = nums[i / 2];
            }
            else{
                ans[i] = nums[size + i / 2];
            }
        }
        return ans;
    }
};