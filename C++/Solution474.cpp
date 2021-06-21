#include <iostream>
#include <vector>

#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;


typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<vii> viii;

class Solution474 {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size = strs.size();
        vector<pii> vec(size);
        for(int i = 0; i < size; i++){
            string cur = strs[i];
            int x = 0, y = 0;
            for(auto ele: cur){
                if(ele == '0'){
                    x ++;
                }
                else{
                    y ++;
                }
            }
            vec[i] = {x, y};
        }
        viii dp(size + 1, vii(m + 1, vi(n + 1)));
        for(int i = 1; i <= size; i++){
            int x = vec[i - 1].first, y = vec[i - 1].second;
            for(int j = 0; j <= m; j++){
                for(int k = 0; k <= n; k++){
                    dp[i][j][k] = dp[i - 1][j][k];
                    if(x <= j && y <= k){
                        dp[i][j][k] = max(1 + dp[i - 1][j - x][k - y], dp[i][j][k]);
                    }
                }
            }
        }
        return dp[size][m][n];
    }
};