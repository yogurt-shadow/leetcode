import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.LinkedList;

class Solution1631 {
	int[] row = {-1, 1, 0, 0};
	int[] col = {0, 0, -1, 1};
	int m;
	int n;

    public int minimumEffortPath(int[][] heights) {
    	m = heights.length;
        n = heights[0].length;
        if(m == 1 && n == 1){
            return 0;
        }
        UnionFind uf = new UnionFind(m * n);
        List<int[]> list = new LinkedList<>();
        int[] row = {0, 1};
        int[] col = {1, 0};
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < 2; k++){
                    if(i + row[k] < m && j + col[k] < n){
                        list.add(new int[]{index(i, j), index(i + row[k], j + col[k]), Math.abs(heights[i][j] - heights[i + row[k]][j + col[k]])});
                    }
                }
            }
        }
        Collections.sort(list, new Comparator<int[]>(){
            @Override
            public int compare(int[] edge1, int[] edge2){
                return edge1[2] - edge2[2];
            }
        });
        int index = 0;
        int result = -1;
        while(!uf.is_connected(0, m * n - 1)){
            int[] edge = list.get(index);
            uf.connect(edge[0], edge[1]);
            result = edge[2];
            index += 1;
        }
        return result;
    }

    private int index(int x, int y){
    	return x * n + y;
    }

    public static void main(String[] args){
    	Solution1631 s = new Solution1631();
    	int[][] test1 = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};
    	System.out.println(s.minimumEffortPath(test1));
    }
}