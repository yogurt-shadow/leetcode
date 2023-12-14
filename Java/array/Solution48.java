class Solution48 {
	public void rotate(int[][] matrix) {
		int n = matrix.length;
		int[][] copy = new int[n][n];
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				copy[i][j] = matrix[i][j];
			}
		}
		int col = n - 1;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				matrix[j][col] = copy[i][j];
			}
			col -= 1;
		}
	}

    public static void main(String[] args){
    	Solution48 s = new Solution48();
    	int[][] test = new int[][]{{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
    	s.rotate(test);
    	for(int i = 0; i < 4; i++){
    		for(int j = 0; j < 4; j++){
    			System.out.print(test[i][j] + " ");
    		}
    		System.out.println();
    	}
    }
}