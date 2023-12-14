class Solution947 {
    public int removeStones(int[][] stones) {
    	int size = stones.length;
    	UnionFind uf = new UnionFind(size);
    	for(int i = 0; i < size; i++){
    		for(int j = 0; j < i; j++){
    			if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
    				uf.connect(i, j);
    			}
    		}
    	}
    	int number = uf.size();
    	return size - uf.size();
    }
}