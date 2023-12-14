class Solution37 {
    public void solveSudoku(char[][] board) {
    	int[] row = new int[81];
    	int[] col = new int[81];
    	int index = 0;
    	for(int i = 0; i < 9; i++){
    		for(int j = 0; j < 9; j++){
    			if(board[i][j] == '.'){
    				row[index] = i;
    				col[index] = j;
    				index += 1;
    			}
    		}
    	}

    	int[] x = new int[index];
    	int[] y = new int[index];
    	System.arraycopy(row, 0, x, 0, index);
    	System.arraycopy(col, 0, y, 0, index);
    	System.out.println(dfs(board, x, y, 0));
    }

    private void print(char[][] board){
       for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){

            if(j == 8){
                System.out.print(board[i][j]);
                continue;
            }
            System.out.print(board[i][j] + "  ");
             if((j  + 1) % 3 == 0){
                System.out.print("| ");
            }
        }
        if((i + 1) % 3 == 0){
            System.out.println();
            for(int k = 0; k < 30; k++){
            System.out.print("-");
        }
        }
        System.out.println();
       }
    }

    private void printline(){

    }

    private boolean dfs(char[][] board, int[] x, int[] y, int position){
        for(char str = '1'; str <= '9'; str++){
            board[x[position]][y[position]] = str;
            if(isValidSudoku(board) && position == x.length - 1){
                return true;
            }

            if(!isValidSudoku(board)){
                continue;
            }

            if(dfs(board, x, y, position + 1)){
                return true;
            }
        }
		board[x[position]][y[position]] = '.';
        return false;
    }

   

    private boolean isValidSudoku(char[][] board) {
    	for(int i = 0; i < 9; i++){
    		char[] line = board[i];
    		int[] freq = new int[9];
    		for(char cur: line){
    			if(cur != '.'){
    			if(freq[cur - '1'] > 0){
    				return false;
    			}
    			freq[cur - '1']  = 1;
    		}
    		}
    	}

    	for(int j = 0; j < 9; j++){
    		int[] freq = new int[9];
    		for(int i = 0; i < 9; i++){
    			char cur = board[i][j];
    			if(cur != '.'){
    			if(freq[cur - '1'] > 0){
    				return false;
    			}
    			freq[cur - '1'] = 1;
    		}
    	}
    	}

    	int[] row = new int[]{0, 0, 0, 3, 3, 3, 6, 6, 6};
    	int[] col = new int[]{0, 3, 6, 0, 3, 6, 0, 3, 6};
    	for(int index = 0; index < 9; index++){
    		int[] freq = new int[9];
    		for(int i = row[index]; i < row[index] + 3; i++){
    			for(int j = col[index]; j < col[index] + 3; j++){
    				char cur = board[i][j];
    				if(cur != '.'){
    					if(freq[cur - '1'] > 0){
    						return false;
    					}
    					freq[cur - '1'] = 1;
    				}
    			}
    		}
    	}
    	return true;
    }

    public static void main(String[] args){
    	Solution37 s = new Solution37();
    	char[][] board = new char[][]{{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    	s.print(board);
        s.solveSudoku(board);
        s.print(board);
    }
}