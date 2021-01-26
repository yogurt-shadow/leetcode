import java.util.HashSet;
import java.util.Set;

class Solution684 {
    public int[] findRedundantConnection(int[][] edges) {
    	int size = -1;
    	for(int[] edge: edges){
    		size = Math.max(size, edge[0]);
    		size = Math.max(size, edge[1]);
    	}
   loop: for(int i = edges.length - 1; i >= 0; i--){
            UnionFind uf = new UnionFind(size);
            for(int j = 0; j < edges.length; j++){
                if(j == i){
                    continue;
                }
                if(uf.is_connected(edges[j][0] - 1, edges[j][1] - 1)){
                    continue loop;
                }
                uf.connect(edges[j][0] - 1, edges[j][1] - 1);
            }
            return new int[]{edges[i][0], edges[i][1]};
        }
        return new int[]{-1, -1};
    }

    public static void main(String[] args){
        Solution684 s = new Solution684();
        int[][] edges1 = {{1, 2}, {1, 3}, {2, 3}};
        int[] result1 = s.findRedundantConnection(edges1);
        for(int ele: result1){
            System.out.print(ele + " ");
        }

        int[][] edges2 = {{1, 2}, {2, 3}, {3, 4}, {1, 4}, {1, 5}};
        int[] result2 = s.findRedundantConnection(edges2);
        for(int ele: result2){
            System.out.print(ele + " ");
        }

        Set<Integer> set = new HashSet<>();
        set.add(2);
        set.add(3);
        set.remove(2);
        for(Integer ele: set){
        	System.out.println(ele);
		}
    }
}