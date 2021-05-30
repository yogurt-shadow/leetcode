#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using ll = long long;

using namespace std;

class Solution4{
public:
    int stoneGameVIII(vector<int> &stones)
    {
        int size = stones.size();
        vector<int> sum(size + 1);
        for(int i = 1; i <= size; i++){
            sum[i] = sum[i - 1] + stones[i - 1];
        }
        vector<int> dp(size);
        dp[size - 1] = sum[size];
        for(int i = size - 2; i >= 1; i--){
            dp[i] = max(dp[i + 1], sum[i + 1] - dp[i + 1]);
        }
        return dp[1];
    }
};

int main(){
    
    
    return 0;
}