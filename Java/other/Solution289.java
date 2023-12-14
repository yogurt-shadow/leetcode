class Solution289 {
    public void gameOfLife(int[][] board) {
    	int m = board.length;
    	int n = board[0].length;
    	int[][] copy = new int[m][n];
    	int[] col = {-1, -1, -1, 0, 0, 1, 1, 1};
    	int[] row = {-1, 0, 1, -1, 1, -1, 0, 1};
    	for(int i = 0; i < m; i++){
    		for(int j = 0; j < n; j++){
    			copy[i][j] = board[i][j];
    		}
    	}
    	for(int i = 0; i < m; i++){
    		for(int j = 0; j < n; j++){
    			int life = 0;
    			for(int k = 0; k < 8; k++){
    				int xx = i + row[k];
    				int yy = j + col[k];
    				if(xx >= 0 && xx < m && yy >= 0 && yy < n){
    					if(copy[xx][yy] == 1){
    						life += 1;
    					}
    				}
    			}
    			if(copy[i][j] == 1){
    				if(life < 2 || life > 3){
    					board[i][j] = 0;
    				}
    			}
    			else{
    				if(life == 3){
    					board[i][j] = 1;
    				}
    			}
    		}
    	}
    }

    public static void main(String[] args){
    	Solution289 s = new Solution289();
    	int[][] test = {{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}};
    	s.gameOfLife(test);
    }
}