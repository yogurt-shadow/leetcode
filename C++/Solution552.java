class Solution552 {
    final int MOD = 1000000007;

    public int checkRecord(int n) {
        int[][][] dp = new int[n + 1][2][3];
        dp[0][0][0] = 1;
        for(int len = 1; len <= n; len++){
            // last: L
            for(int numA = 0; numA < 2; numA++){
                for(int nL = 1; nL < 3; nL++){
                    dp[len][numA][nL] += dp[len - 1][numA][nL - 1];
                    dp[len][numA][nL] %= MOD;
                }
            }
            // last: A
            for(int nL = 0; nL < 3; nL++){
                dp[len][1][0] += dp[len - 1][0][nL];
                dp[len][1][0] %= MOD;
            }
            // last: P
            for(int numA = 0; numA < 2; numA++){
                for(int nL = 0; nL < 3; nL++){
                    dp[len][numA][0] += dp[len - 1][numA][nL];
                    dp[len][numA][0] %= MOD;
                }
            }
        }
        int ans = 0;
        for(int numA = 0; numA < 2; numA++){
            for(int nL = 0; nL < 3; nL++){
                ans += dp[n][numA][nL];
                ans %= MOD;
            }
        }
        return ans;
    }
}