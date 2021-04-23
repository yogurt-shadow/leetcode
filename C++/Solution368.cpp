#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<stack>
#include<queue>
#include<set>

using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI> VII;
typedef vector<VII> VIII;

class Solution368 {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        VI dp(nums.size(), 1);
        int m = 1;
        for(int i = 1; i < nums.size(); i++){
            for(int j = i - 1; j >= 0; j--){
                if(nums[i] % nums[j] == 0){
                    dp[i] = max(dp[j] + 1, dp[i]);
                    m = max(m, dp[i]);
                }
            }
        }
        VI res;
        for(int k = nums.size() - 1; k >= 0; k--){
            if(dp[k] == m && (res.size() == 0 || res.size() > 0 && res.back() % nums[k] == 0)){
                res.push_back(nums[k]);
                m --;
            }
        }
        return res;
    }
};