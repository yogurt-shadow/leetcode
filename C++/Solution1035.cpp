#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <stack>

using namespace std;
typedef long long ll;

class Solution1035 {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size(), size2 = nums2.size();
        vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1));
        for(int i = 1; i <= size1; i++){
            for(int j = 1; j <= size2; j++){
                if(nums1[i - 1] == nums2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }  
        return dp[size1][size2];
    }
};