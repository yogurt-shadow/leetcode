class Solution63 {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        if(obstacleGrid[0][0] == 1){
            return 0;
        }
    	int m = obstacleGrid.length;
    	int n = obstacleGrid[0].length;
    	int[][] dp = new int[m][n];
    	if(m == 1){
    		for(int ele: obstacleGrid[0]){
    			if(ele == 1){
    				return 0;
    			}
    		}
    		return 1;
    	}
    	if(n == 1){
    		for(int i = 0; i < m; i++){
    			if(obstacleGrid[i][0] == 1){
    				return 0;
    			}
    		}
    		return 1;
    	}
    	boolean hasobstacle1 = false;
    	for(int i = m - 1; i >= 0; i--){
    		dp[i][n - 1] = hasobstacle1 ? 0 : 1;
    		if(obstacleGrid[i][n - 1] == 1){
    			hasobstacle1 = true;
    		}
    	}
    	boolean hasobstacle2 = false;
    	for(int i = n - 1; i >= 0; i--){
    		dp[m - 1][i] = hasobstacle2 ? 0 : 1;
    		if(obstacleGrid[m - 1][i] == 1){
    			hasobstacle2 = true;
    		}
    	}
    	for(int i = m - 2; i >= 0; i--){
    		for(int j = n - 2; j >= 0; j--){
    			if(obstacleGrid[i + 1][j] == 1 && obstacleGrid[i][j + 1] == 1){
    				dp[i][j] = 0;
    			}
    			else if(obstacleGrid[i + 1][j] == 1){
    				dp[i][j] = dp[i][j + 1];
    			}
    			else if(obstacleGrid[i][j + 1] == 1){
    				dp[i][j] = dp[i + 1][j];
    			}
    			else{
    				dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
    			}
    		}
    	}
    	return dp[0][0];
    }

    public static void main(String[] args){
        Solution63 s = new Solution63();
        int[][] test1 = {{0}, {1}};
        System.out.println(s.uniquePathsWithObstacles(test1));
    }
}