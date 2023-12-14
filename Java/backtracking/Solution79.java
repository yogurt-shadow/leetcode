import java.util.Set;
import java.util.HashSet;

class Solution79 {
    public boolean exist(char[][] board, String word) {
    	Set<Integer[]> set = new HashSet<>();
    	return dfs(board, set, 0, word);
    }

    private boolean dfs(char[][] board, Set<Integer[]> set, int index, String word){
    	char cur = word.charAt(index);
        for(int i = 0; i < board.length; i++){
            for(int j = 0; j < board[0].length; j++){
                if(board[i][j] == cur){
                    Integer[] array = new Integer[]{i, j};
                    set.add(array);
                    if(word.length() - 1 == index){
                        return true;
                    }
                    if(dfs2(i - 1, j, board, set, index + 1, word)){
                        return true;
                    }
                    if(dfs2(i + 1, j, board, set, index + 1, word)){
                        return true;
                    }
                    if(dfs2(i, j - 1, board, set, index + 1, word)){
                        return true;
                    }
                    if(dfs2(i, j + 1, board, set, index + 1, word)){
                        return true;
                    }
                    set.remove(array);
                }
            }
        }
        return false;
    }

    private boolean dfs2(int row, int col, char[][] board, Set<Integer[]> set, int index, String word){
        if(row < 0 || row >= board.length || col < 0 || col >= board[0].length){
            return false;
        }
        char cur = word.charAt(index);
        if(board[row][col] != cur){
            return false;
        }
        for(Integer[] ele: set){
        	if(ele[0] == row && ele[1] == col){
        		return false;
			}
		}
        if(index == word.length() - 1){
            return true;
        }
        Integer[] array = new Integer[]{row, col};
        set.add(array);
        if(dfs2(row - 1, col, board, set, index + 1, word)){
            return true;
        }
        if(dfs2(row + 1, col, board, set, index + 1, word)){
            return true;
        }
        if(dfs2(row, col - 1, board, set, index + 1, word)){
            return true;
        }
        if(dfs2(row, col + 1, board, set, index + 1, word)){
            return true;
        }
        set.remove(array);
        return false;
    }

    public static void main(String[] args){
        Solution79 s = new Solution79();
        char[][] board = new char[][]{new char[]{'A', 'B', 'C', 'E'}, new char[]{'S', 'F', 'C', 'S'}, new char[]{'A', 'D', 'E', 'E'}};
        System.out.println(s.exist(board, "ABCB"));
    }
}