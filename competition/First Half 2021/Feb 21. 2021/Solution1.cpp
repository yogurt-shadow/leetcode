#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

class Solution {
public:
    const int MOD = 1000000000 + 7;

    int purchasePlans(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        ll res = 0;
        int index1 = 0;
        int index2 = nums.size() - 1;
        while(index1 < nums.size() && nums[index1] < target){
            while(index2 > index1 && nums[index1] + nums[index2] > target){
                index2--;
            }
            if(index2 <= index1){
                break;
            }
            
            cout << index1 << index2 << endl;
            res += index2 - index1;
            index1++;
            res %= MOD;
        }
        return res % MOD;
    }
};