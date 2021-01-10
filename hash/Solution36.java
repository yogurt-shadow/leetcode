class Solution36 {
    public boolean isValidSudoku(char[][] board) {
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
    	Solution36 s = new Solution36();
    	char[][] test = new char[][]{{'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'}};
    	System.out.println(s.isValidSudoku(test));
    }
}