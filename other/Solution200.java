import java.util.Set;
import java.util.HashSet;

class Solution200 {
	int number = 0;
	Set<Integer> set = new HashSet<>();
	int[] x = new int[]{0, 0, -1, 1};
	int[] y = new int[]{-1, 1, 0, 0};

    public int numIslands(char[][] grid) {
    	if(grid.length == 0){
    		return number;
    	}
    	for(int i = 0; i < grid.length; i++){
    		for(int j = 0; j < grid[0].length; j++){
    			if(grid[i][j] == '1' && !set.contains(i * grid[0].length + j)){
    				number += 1;
    				dfs(grid, i, j);
    			}
    		}
    	}
    	return number;
    }

    private void dfs(char[][] grid, int row, int col){
    	set.add(row * grid[0].length + col);
    	for(int index = 0; index < 4; index++){
    		if(row + x[index] >= 0 && row + x[index] < grid.length && col + y[index] >= 0 && col + y[index] < grid[0].length && grid[row + x[index]][col + y[index]] == '1'){
    			int cur = (row + x[index]) * grid[0].length + col + y[index];
    			if(!set.contains(cur)){
    			set.add(cur);
    			dfs(grid, row + x[index], col + y[index]);
    		}
    		}
    	}
    }

}