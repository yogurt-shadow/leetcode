class Solution1579 {
    public int maxNumEdgesToRemove(int n, int[][] edges) {
    	UnionFind uf = new UnionFind(n);
        UnionFind uf2 = new UnionFind(n);

    	int edge_number = 0;
    	for(int[] edge: edges){
    		if(edge[0] != 3){
    			continue;
    		}
    		int left = edge[1] - 1;
    		int right = edge[2] - 1;
    		if(!uf.is_connected(left, right)){
    			uf.connect(left, right);
                uf2.connect(left, right);
    			edge_number += 1;
    		}
    	}
        for(int[] edge: edges){
            if(edge[0] == 3){
                continue;
            }
            int left = edge[1] - 1;
            int right = edge[2] - 1;
            if(edge[0] == 1){
                if(!uf.is_connected(left, right)){
                    edge_number += 1;
                    uf.connect(left, right);
                }
            }
            else{
                if(!uf2.is_connected(left, right)){
                    edge_number += 1;
                    uf2.connect(left, right);
                }
            }
        }
    	return uf.size() == 1 && uf2.size() == 1 ? edges.length - edge_number : -1;
    }

    public static void main(String[] args){
    	Solution1579 s = new Solution1579();
    	int[][] edges1 = {{3, 1, 2}, {3, 2, 3}, {1, 1, 4}, {2, 1, 4}};
    	System.out.println(s.maxNumEdgesToRemove(4, edges1));
    }
}