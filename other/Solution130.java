import java.util.Set;
import java.util.HashSet;

class Solution130 {
	Set<Integer> set = new HashSet<>();
	int[] x = new int[]{-1, 1, 0, 0};
	int[] y = new int[]{0, 0, -1, 1};

    public void solve(char[][] board) {
        if(board.length == 0){
            return;
        }
    	for(int row = 0; row < board.length; row++){
    		if(board[row][0] == 'O'){
    			dfs(board, row, 0);
    		}
    		if(board[row][board[0].length - 1] == 'O'){
    			dfs(board, row, board[0].length - 1);
    		}
    	}

    	for(int col = 0; col < board[0].length; col++){
    		if(board[0][col] == 'O'){
    			dfs(board, 0, col);
    		}
    		if(board[board.length - 1][col] == 'O'){
    			dfs(board, board.length - 1, col);
    		}
    	}

    	for(int i = 0; i < board.length; i++){
    		for(int j = 0; j < board[0].length; j++){
    			if(board[i][j] == 'O' && !set.contains(i * board[0].length + j)){
    				board[i][j] = 'X';
    			}
    		}
    	}	
    }

    private void dfs(char[][] board, int row, int col){
    	set.add(row * board[0].length + col);
    	for(int index = 0; index < 4; index++){
    		if(row + x[index] >= 0 && row + x[index] < board.length && col + y[index] >= 0 && col + y[index] < board[0].length && board[row + x[index]][col + y[index]] == 'O'){
    			int cur = (row + x[index]) * board[0].length + col + y[index];
    			if(!set.contains(cur)){
    				dfs(board, row + x[index], col + y[index]);
    			}
    		}
    	}
    }

    public static void main(String[] args){
    	Solution130 s = new Solution130();
    	char[][] board = new char[][]{new char[]{'X', 'X', 'X', 'X'}, new char[]{'X', 'O', 'O', 'X'}, new char[]{'X', 'X', 'O', 'X'}, new char[]{'X', 'O', 'X', 'X'}};
    	s.solve(board);
    }
}