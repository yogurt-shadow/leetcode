#include<iostream>
#include<vector>

using namespace std;

class Solution132 {
public:
    vector<vector<int>> dp;
    vector<int> mem;

    int minCut(string s) {
        int size = s.length();
        dp.resize(size, vector<int>(size));
        for(int i = 0; i < size; i++){
            dp[i][i] = 1;
            if(i + 1 < size){
                if(s[i] == s[i + 1]){
                    dp[i][i + 1] = 1;
                }
            }
        }
        for(int len = 3; len <= size; len++){
            for(int left = 0; left + len - 1 < size; left++){
                int right = left + len - 1;
                if(s[left] == s[right]){
                    dp[left][right] = dp[left + 1][right - 1];
                }
            }
        }
        mem.resize(size, -1);
        return split(size - 1);
    }

    int split(int x){
        if(dp[0][x]){
            return 0;
        }
        if(mem[x] != -1){
            return mem[x];
        }
        int cut = INT_MAX;
        for(int j = 0; j < x; j++){
            if(dp[j + 1][x]){
                cut = min(cut, split(j) + 1);
            }
        }
        mem[x] = cut;
        return cut;
    }
};