class Solution547 {
    public int findCircleNum(int[][] isConnected) {
    	UnionFind uf = new UnionFind(isConnected.length);
    	for(int i = 0; i < isConnected.length; i++){
    		for(int j = 0; j < isConnected[0].length; j++){
    			if(isConnected[i][j] == 1){
    				uf.connect(i, j);
				}
    		}
    	}
    	return uf.size();
    }

    public static void main(String[] args){
    	Solution547 s = new Solution547();
    	int[][] test = new int[][]{new int[]{1, 1, 0}, new int[]{1, 1, 0}, new int[]{0, 0, 1}};
    	System.out.println(s.findCircleNum(test));
    }
}