#include<iostream>
#include<vector>

using namespace std;

const int MAX = 0x3f3f3f3f;

class Solution3 {
public:
    int minSpaceWastedKResizing(vector<int> &nums, int k) {
        int size = nums.size();
        vector<vector<int>> g(size, vector<int>(size)); // g[i][j] is from i to j the value of max * len - sum[i][j]
        for(int i = 0; i < size; i++){ 
            int sum = 0;
            int m = INT_MIN; 
            for(int j = i; j < size; j++){
                m = max(m, nums[j]);
                sum += nums[j];
                g[i][j] = m * (j - i + 1) - sum;
            }
        }
        vector<vector<int>> dp(size, vector<int>(k + 2, MAX));
        for(int i = 0; i < size; i++){
            for(int j = 1; j <= k + 1; j++){
                for(int ii = 0; ii <= i; ii++){
                    if(ii == 0){
                        dp[i][j] = min(dp[i][j], g[ii][i]);
                    }
                    else{
                        dp[i][j] = min(dp[i][j], dp[ii - 1][j - 1] + g[ii][i]);
                    }
                }
            }
        }
        return dp[size - 1][k + 1];
    }
};

int main(){

    return 0;
}