#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;

typedef long long ll;

class Solution96 {
public:
    vector<vector<int>> dp;

    int numTrees(int n) {
        dp.resize(n + 1, vector<int>(n + 1));
        return numTrees(1, n);
    }

    int numTrees(int start, int end){
        if(start >= end) return 1;
        if(dp[start][end]) return dp[start][end];
        for(int i = start; i <= end; i++){
            dp[start][end] += (numTrees(start, i - 1) * numTrees(i + 1, end));
        }
        return dp[start][end];
    }
};