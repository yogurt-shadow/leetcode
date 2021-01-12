import java.util.List;
import java.util.LinkedList;


class Solution52 {
    int x = 0;
    public int totalNQueens(int n) {
        char[][] board = new char[n][n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                board[i][j] = '.';
            }
        }
        put(board, 0);
        return x;
    }

    private void put(char[][] board, int row){
        int n = board.length;
        for(int col = 0; col < n; col++){
            board[row][col] = 'Q';
            if(row == n - 1 && is_valid(board)){
                x += 1;
                board[row][col] = '.';
                return;
            }
            if(!is_valid(board)){
            	board[row][col] = '.';
                continue;
            }
            put(board, row + 1);
            board[row][col] = '.';
        }
    }

    private boolean is_valid(char[][] board){
        int[] position = new int[board.length];
        loop: for(int i = 0; i < board.length; i++){
            for(int j = 0; j < board.length; j++){
                if(board[i][j] == 'Q'){
                    position[i] = j;
                    continue loop;
                }
            }
            position[i] = -1;
        }
        for(int i = 0; i < board.length; i++){
            for(int j = i + 1; j < board.length; j++){
                if(eaten(i, position[i], j, position[j])){
                    return false;
                }
            }
        }
        return true;
    }

   private boolean eaten(int row1, int col1, int row2, int col2){
        if(col1 == -1 || col2 == -1){
            return false;
        }
        if(row1 == row2 || col1 == col2){
            return true;
        }
        return Math.abs(row1 - row2) == Math.abs(col1 - col2);
   }

    public static void main(String[] args){
    	Solution52 s  = new Solution52();
    	System.out.println(s.totalNQueens(11));
    }
}