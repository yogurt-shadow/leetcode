class Solution59 {
    public int[][] generateMatrix(int n) {
    	int[][] result = new int[n][n];
    	for(int i = 0; i < n; i++){
    		for(int j = 0; j < n; j++){
    			result[i][j] = 0;
    		}
    	}

    	fill(result, 0, 0, 1, "right");
    	return result;
    }

    private void fill(int[][] result, int row, int col, int number, String direction){
    	int n = result.length;
    	if(number == n * n + 1){
    		return;
    	}
    	result[row][col] = number;
    	switch(direction){
    		case "right":
    		if(col + 1 >= n || result[row][col + 1] != 0){
    			fill(result, row + 1, col, number + 1, "down");
    		}
    		else{
    			fill(result, row, col + 1, number + 1, "right");
    		}
    		break;

    		case "down":
    		if(row + 1 >= n || result[row + 1][col] != 0){
    			fill(result, row, col - 1, number + 1, "left");
    		}
    		else{
    			fill(result, row + 1, col, number + 1, "down");
    		}
    		break;

    		case "left":
    		if(col - 1 < 0 || result[row][col - 1] != 0){
    			fill(result, row - 1, col, number + 1, "up");
    		}
    		else{
    			fill(result, row, col - 1, number + 1, "left");
    		}
    		break;

    		case "up":
    		if(row - 1 < 0 || result[row - 1][col] != 0){
    			fill(result, row, col + 1, number + 1, "right");
    		}
    		else{
    			fill(result, row - 1, col, number + 1, "up");
    		}
    		break;

    		default:
    		return;
    	}
    }

    public static void main(String[] args){
    	Solution59 s = new Solution59();
    	int[][] result = s.generateMatrix(3);
    	for(int i = 0; i < 3; i++){
    		for(int j = 0; j < 3; j++){
    			System.out.print(result[i][j] + " ");
    		}
    		System.out.println();
    	}
    }
}