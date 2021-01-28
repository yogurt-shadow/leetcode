class Solution62 {
    public int uniquePaths(int m, int n) {
    	if(m == 1 || n == 1){
    		return 1;
    	}
    	int[][] dp = new int[m][n];
    	dp[m - 1][n - 1] = 1;
    	dp[m - 2][n - 1] = 1;
    	dp[m - 1][n - 2] = 1;
    	for(int i = m - 1; i >= 0; i--){
    		for(int j = n - 1; j >= 0; j--){
    			if(i + 1 >= m && j + 1 < n){
    				dp[i][j] = dp[i][j + 1];
    			}
    			else if(i + 1 < m && j + 1 >= n){
    				dp[i][j] = dp[i + 1][j];
    			}
    			else if(i + 1 < m && j + 1 < n){
    				dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
    			}
    		}
    	}
    	return dp[0][0];
    }
}