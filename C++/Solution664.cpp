#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <stack>

using namespace std;
typedef long long ll;

class Solution664 {
public:
    int strangePrinter(string s) {
        int size = s.length();
        vector<vector<int>> dp(size, vector<int>(size));
        for(int i = size - 1; i >= 0; i--){
            dp[i][i] = 1;
            for(int j = i + 1; j < size; j++){
                if(s[i] == s[j]){
                    dp[i][j] = dp[i][j - 1];
                }
                else{
                    int m = size + 1;
                    for(int k = i; k <= j - 1; k++){
                        m = min(m, dp[i][k] + dp[k + 1][j]);
                    }
                    dp[i][j] = m;
                }
            }
        }
        return dp[0][size - 1];
    }
};

int main(){
    int a[3] = {1, 2, 3};
    int* p = a + 1;
    cout << (*(p++))++;
    return 0;
}