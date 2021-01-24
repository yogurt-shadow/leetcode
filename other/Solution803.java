class Solution803 {
    public int[] hitBricks(int[][] grid, int[][] hits) {
    	int[] result = new int[hits.length];
    	for(int i = 0; i < hits.length; i++){
    		int row = hits[i][0];
    		int col = hits[i][1];
    		if(grid[row][col] == 0){
    			result[i] = 0;
    			continue;
    		}
    		grid[row][col] = 0;
    		int last = grid.length * grid[0].length;
    		UnionFind uf = update(grid);
    		int cur = 0;
    		for(int index1 = 0; index1 < grid.length; index1++){
    			for(int index2 = 0; index2 < grid[0].length; index2++){
    				if(grid[index1][index2] == 1 && !uf.is_connected(convert(index1, index2, grid), last)){
    					grid[index1][index2] = 0;
    					cur += 1;
    				}
    			}
    		}
    		result[i] = cur;
    	}
    	return result;
    }

    private UnionFind update(int[][] grid){
    	UnionFind uf = new UnionFind(grid.length * grid[0].length + 1);
    	int last = grid.length * grid[0].length;
    	for(int col = 0; col < grid[0].length; col++){
    		if(grid[0][col] == 1){
    			uf.connect(convert(0, col, grid), last);
    		}
    	}
    	int[] x = new int[]{-1, 1, 0, 0};
    	int[] y = new int[]{0, 0, -1, 1};
    	for(int row = 0; row < grid.length; row++){
    		for(int col = 0; col < grid[0].length; col++){
    			if(grid[row][col] == 1){
    				for(int index = 0; index < 4; index++){
    					if(row + x[index] >= 0 && row + x[index] < grid.length && col + y[index] >= 0 && col + y[index] < grid[0].length && grid[row + x[index]][col + y[index]] == 1){
    						uf.connect(convert(row, col, grid), convert(row + x[index], col + y[index], grid));
    					}
    				}
    			}
    		}
    	}
    	return uf;
    }

    private int convert(int row, int col, int[][] grid){
    	return row * grid[0].length + col;
    }

    public static void main(String[] args){
    	Solution803 s = new Solution803();
    	int[][] grid1 = new int[][]{new int[]{1, 0, 0, 0}, new int[]{1, 1, 1, 0}};
    	int[][] hits1 = new int[][]{new int[]{1, 0}};
    	int[] result1 = s.hitBricks(grid1, hits1);
    	for(int ele: result1){
    		System.out.print(ele + " ");
    	}
        System.out.println();

        int[][] grid2 = new int[][]{new int[]{1, 0, 0, 0}, new int[]{1, 1, 0, 0}};
        int[][] hits2 = new int[][]{new int[]{1, 1}, new int[]{1, 0}};
        int[] result2  =s.hitBricks(grid2, hits2);
        for(int ele: result2){
            System.out.print(ele + " ");
        }
    }
}