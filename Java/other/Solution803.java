class Solution803 {
   public int[] hitBricks(int[][] grid, int[][] hits) {
        int h = grid.length, w = grid[0].length;
        
        UnionFind uf = new UnionFind(h * w + 1);
        int[][] status = new int[h][w];
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                status[i][j] = grid[i][j];
            }
        }
        for (int i = 0; i < hits.length; i++) {
            status[hits[i][0]][hits[i][1]] = 0;
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (status[i][j] == 1) {
                    if (i == 0) {
                        uf.connect(h * w, i * w + j);
                    }
                    if (i > 0 && status[i - 1][j] == 1) {
                        uf.connect(i * w + j, (i - 1) * w + j);
                    }
                    if (j > 0 && status[i][j - 1] == 1) {
                        uf.connect(i * w + j, i * w + j - 1);
                    }
                }
            }
        }
        int[][] directions = {{0, 1},{1, 0},{0, -1},{-1, 0}};
        int[] ret = new int[hits.length];
        for (int i = hits.length - 1; i >= 0; i--) {
            int r = hits[i][0], c = hits[i][1];
            if (grid[r][c] == 0) {
                continue;
            }
            int prev = uf.size(h * w);

            if (r == 0) {
                uf.connect(c, h * w);
            }
            for (int[] direction : directions) {
                int dr = direction[0], dc = direction[1];
                int nr = r + dr, nc = c + dc;
                
                if (nr >= 0 && nr < h && nc >= 0 && nc < w) {
                    if (status[nr][nc] == 1) {
                        uf.connect(r * w + c, nr * w + nc);
                    }
                }
            }
            int size = uf.size(h * w);
            ret[i] = Math.max(0, size - prev - 1);
            status[r][c] = 1;
        }
        return ret;
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