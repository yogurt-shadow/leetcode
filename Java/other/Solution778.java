import java.util.Map;
import java.util.HashMap;

class Solution778 {
	private int m;
	private int n;

    public int swimInWater(int[][] grid) {
    	m = grid.length;
    	n = grid[0].length;
    	Map<Integer, Integer> map = new HashMap<>();
    	int index = 0;
    	for(int[] ele1: grid){
    		for(int ele2: ele1){
    			map.put(ele2, index);
    			index += 1;
    		}
    	}
    	int[] row = {0, 0, 1, -1};
    	int[] col = {-1, 1, 0, 0};
    	int depth = 0;
    	UnionFind uf = new UnionFind(m * n);
    	while(!uf.is_connected(0, m * n - 1)){
    		int position = map.get(depth);
    		int xx = convert(position)[0];
    		int yy = convert(position)[1];
    		for(int i = 0; i < 4; i++){
    			if(xx + row[i] >= 0 && xx + row[i] < m && yy + col[i] >= 0 && yy + col[i] < n && grid[xx + row[i]][yy + col[i]] <= depth){
    				uf.connect(position, map.get(grid[xx + row[i]][yy + col[i]]));
    			}
    		}
    		depth += 1;
    	}
    	return depth - 1;
    }

    private int[] convert(int index){
    	return new int[]{index / n, index % n};
    }

    public static void main(String[] args){
    	Solution778 s = new Solution778();
    	int[][] grid = {{0, 1, 2, 3, 4}, {24, 23, 22, 21, 5}, {12, 13, 14, 15, 16}, {11, 17, 18, 19, 20}, {10, 9, 8, 7, 6}};
    	System.out.println(s.swimInWater(grid));
    }
}