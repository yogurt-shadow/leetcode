/**
* Solution304
*/

class NumMatrix {
	private int[][] matrix;
	private int[][] dp;
	private int m;
	private int n;

    public NumMatrix(int[][] matrix) {
    	this.matrix = matrix;
    	m = matrix.length;
    	if(m == 0){
    		return;
    	}
    	n = matrix[0].length;
    	dp = new int[m][n];
    	dp[0][0] = matrix[0][0];
    	for(int i = 1; i < m; i++){
    		dp[i][0] = dp[i - 1][0] + matrix[i][0];
    	}
    	for(int i = 1; i < n; i++){
    		dp[0][i] = dp[0][i - 1] + matrix[0][i];
    	}
    	for(int i = 1; i < m; i++){
    		for(int j = 1; j < n; j++){
    			dp[i][j] = dp[i - 1][j] - dp[i - 1][j - 1] + dp[i][j - 1] + matrix[i][j];
    		}
    	}
    }
    
    public int sumRegion(int row1, int col1, int row2, int col2) {
    	int part1 = col1 - 1 >= 0 ? dp[row2][col1 - 1] : 0;
    	int part2 = row1 - 1 >= 0 ? dp[row1 - 1][col2] : 0;
    	int part3 = row1 - 1 >= 0 && col1 - 1 >= 0 ? dp[row1 - 1][col1 - 1] : 0;
    	return dp[row2][col2] - part1 - part2 + part3;
    }

    public static void main(String[] args){
    	int[][] matrix = {{3, 0, 1, 4, 2}, {5, 6, 3, 2, 1}, {1, 2, 0, 1, 5}, {4, 1, 0, 1, 7}, {1, 0, 3, 0, 5}};
    	NumMatrix m = new NumMatrix(matrix);
    	System.out.println(m.sumRegion(2, 1, 4, 3));
    }
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */