class Solution959 {
	private int n;
    public int regionsBySlashes(String[] grid) {
    	n = grid.length;
    	UnionFind uf = new UnionFind(n * n * 4);
        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++){
                char cur = grid[row].charAt(col);
                switch(cur){
                    case ' ':
                    for(int i = 0; i < 3; i++){
                        uf.connect(index(row, col, i), index(row, col, i + 1));
                    }
                    break;

                    case '/':
                    uf.connect(index(row, col, 0), index(row, col, 3));
                    uf.connect(index(row, col, 1), index(row, col, 2));
                    break;

                    case '\\':
                    uf.connect(index(row, col, 0), index(row, col, 1));
                    uf.connect(index(row, col, 2), index(row, col, 3));
                    break;

                    default:
                    break;
                }
                if(col + 1 < n){
                    uf.connect(index(row, col, 1), index(row, col + 1, 3));
                }
                if(row + 1 < n){
                    uf.connect(index(row, col, 2), index(row + 1, col, 0));
                }
            }
        }
    	return uf.size();
    }

    private int index(int row, int col, int x){
    	return row * n * 4 + col * 4 + x;
    }

    public static void main(String[] args){
    	Solution959 s = new Solution959();
        String[] test1 = {"\\/", "/\\"};
        System.out.println(s.regionsBySlashes(test1));
    }
}