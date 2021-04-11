#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

class Solution1{
public:
    int arraySign(vector<int>& nums) {
        int sign = 1;
        for(auto ele: nums){
            if(ele == 0){
                return 0;
            }
            if(ele < 0){
                sign = -sign;
            }
        }
        return sign;
    }
};