import java.util.Set;
import java.util.HashSet;

class Solution1559 {
	private Set<Integer> visited;
	private Set<Integer> set;
	private int m, n;
	private int[] row = {-1, 1, 0, 0};
	private int[] col = {0, 0, -1, 1};

    public boolean containsCycle(char[][] grid) {
    	m = grid.length;
    	n = grid[0].length;
    	set = new HashSet<>();
    	visited = new HashSet<>();
    	for(int i = 0; i < m; i++){
    		for(int j = 0; j < n; j++){
    			if(!visited.contains(index(i, j))){
    				set.clear();
    				if(dfs(i, j, -1, -1, grid)){
    					return true;
    				}
    			}
    		}
    	}
    	return false;
    }

    private boolean dfs(int x1, int y1, int x2, int y2, char[][] grid){
    	visited.add(index(x1, y1));
    	set.add(index(x1, y1));
    	char cur = grid[x1][y1];
    	for(int k = 0; k < 4; k++){
    		int xx = x1 + row[k];
    		int yy = y1 + col[k];
    		if(xx == x2 && yy == y2){
    			continue;
    		}
    		if(xx >= 0 && yy >= 0 && xx < m && yy < n){
    			if(set.contains(index(xx, yy))){
    				return true;
    			}
    			if(grid[xx][yy] == cur){
    				if(dfs(xx, yy, x1, y1, grid)){
    					return true;
    				}
    			}
    		}
    	}
    	return false;
    }

    private int index(int x, int y){
    	return x * n + y;
    }

    public static void main(String[] args){
    	Solution1559 s = new Solution1559();
    	char[][] grid = {{'a','a','a','a'}, {'a','b','b','a'}, {'a','b','b','a'}, {'a','a','a','a'}};
    	System.out.println(s.containsCycle(grid));
    }
}