import java.util.List;
import java.util.LinkedList;

class Solution1219 {
	private int x;
    public int getMaximumGold(int[][] grid) {
    	x = 0;
    	List<Integer[]> path = new LinkedList<>();
    	dfs(path, grid);
    	return x;
    }

    private void dfs(List<Integer[]> path, int[][] grid){
    	int row_n = grid.length;
    	int col_n = grid[0].length;
    	for(int row = 0; row < row_n; row++){
    		for(int col = 0; col < col_n; col++){
    			if(grid[row][col] == 0){
    				continue;
    			}
                x = Math.max(x, grid[row][col]);
    			path.add(new Integer[]{row, col});
                put(path, grid,  grid[row][col], row, col - 1);
                put(path, grid,  grid[row][col], row, col + 1);
                put(path, grid,  grid[row][col], row - 1, col);
                put(path, grid,  grid[row][col], row + 1, col);
                path.remove(path.size() - 1);
    		}
    	}
    }

    private void put(List<Integer[]> path, int[][] grid, int sum, int row, int col){
        if(row < 0 || row >= grid.length || col < 0 || col >= grid[0].length || grid[row][col] == 0){
            return;
        }
        for(Integer[] ele: path){
            if(ele[0] == row && ele[1] == col){
                return;
            }
        }
        x = Math.max(x, grid[row][col] + sum);
        path.add(new Integer[]{row, col});
        put(path, grid, sum + grid[row][col], row, col - 1);
        put(path, grid, sum + grid[row][col], row, col + 1);
        put(path, grid, sum + grid[row][col], row - 1, col);
        put(path, grid, sum + grid[row][col], row + 1, col);
        path.remove(path.size() - 1);
    }

    public static void main(String[] args){
    	Solution1219 s = new Solution1219();
        int[][] grid = new int[][]{new int[]{1, 0, 7}, new int[]{2, 0, 6}, new int[]{3, 4, 5}, new int[]{0, 3, 0}, new int[]{9, 0, 20}};
        System.out.println(s.getMaximumGold(grid));
    	int[][] grid1 = new int[][]{new int[]{0, 6, 0}, new int[]{5, 8, 7}, new int[]{0, 9, 0}};
        System.out.println(s.getMaximumGold(grid1));
	}
}