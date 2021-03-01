#include<iostream>
#include<vector>

using namespace std;

class Solution877 {
public:
    bool stoneGame(vector<int>& piles) {
        int size = piles.size();
        vector<vector<int>> dp(size, vector<int>(size));
        for(int i = 0; i < size; i++){
            dp[i][i] = piles[i];
        }
        for(int j = 1; j < size; j++){
            for(int i = j - 1; i >= 0; i--){
                dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] + dp[i][j - 1]);
            }
        }
        return dp[0][size - 1] > 0;
    }
};

int main(){
    Solution877 s;
    vector<int> test = {5, 3, 4, 5};
    cout << s.stoneGame(test);
    return 0;
}