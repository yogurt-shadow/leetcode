class Solution64 {
    public int minPathSum(int[][] grid) {
    	int m = grid.length;
    	int n = grid[0].length;
    	int[][] path = new int[m][n];
    	path[m - 1][n - 1] = grid[m - 1][n - 1];
    	for(int j = n - 2; j >= 0; j--){
    		path[m - 1][j] = grid[m - 1][j] + path[m - 1][j + 1];
    	}
    	for(int i = m - 2; i >= 0; i--){
    		path[i][n - 1] = grid[i][n - 1] + path[i + 1][n - 1];
    	}
    	for(int i = m - 2; i >= 0; i--){
    		for(int j = n - 2; j >= 0; j--){
    			path[i][j] = grid[i][j] + Math.min(path[i + 1][j], path[i][j + 1]);
    		}
    	}
    	return path[0][0];
    }
}