#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <queue>

using ll = long long;

using namespace std;
typedef vector<pair<int, int>> vii;

typedef pair<int, int> pii;

class Solution3 {
public:
    const int MOD = 1e9 + 7;

    int colorTheGrid(int m, int n) {
        unordered_map<int, vector<int>> line;
        for(int mask = 0; mask < pow(3, m); mask++){
            vector<int> vec;
            int copy = mask;
            for(int j = 0; j < m; j++){
                vec.push_back(copy % 3);
                copy /= 3;
            }
            bool check = true;
            for(int i = 0; i + 1 < vec.size(); i++){
                if(vec[i] == vec[i + 1]){
                    check = false;
                    break;
                }
            }
            if(check){
                line[mask] = push_back(vec);
            }
        }
        unordered_map<int, vector<int>> besides;
        for(auto& [mask1, choice1] : line){
            for(auto& [mask2, choice2] : line){
                bool check = true;
                for(int i = 0; i < choice1.size(); i++){
                    if(choice1[i] == choice2[i]){
                        check = false;
                        break;
                    }
                }
                if(check){
                    besides[mask1].push_back(mask2);
                }
            }
        }
        vector<vector<int>> dp(n, vector<int>(pow(3, m), 0));
        for(auto& [mask, choice] : line){
            dp[0][mask] = 1;
        }
        for(int i = 1; i < n; i++){
            for(auto& [mask, choice] : line){
                for(auto& mask2 : besides[mask]){
                    dp[i][mask] += dp[i - 1][mask2];
                    dp[i][mask] %= MOD;
                }
            }
        }
        int res = 0;
        for(int mask = 0; mask < pow(3, m); mask++){
            res += dp[n - 1][mask];
            res %= MOD;
        }
        return res;
    }
};

int main(){
   
    
    return 0;
}