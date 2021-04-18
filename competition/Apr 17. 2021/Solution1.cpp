#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<stack>
#include<cstring>

using namespace std;
using ll = long long;

class Solution1{
public:
    int minOperations(vector<int>& nums) {
        int res = 0;
        if(nums.size() == 1){
            return res;
        }
        int cur = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > cur){
                cur = nums[i];
            }
            else{
                cur ++;
                res += cur - nums[i];
            }
        }
        return res;
    }
};

int main(){

    
    return 0;
}