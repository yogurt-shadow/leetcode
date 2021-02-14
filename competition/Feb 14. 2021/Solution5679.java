import java.util.Map;
import java.util.HashMap;
import java.util.Set;
import java.util.HashSet;

class Solution5679 {
	Map<Integer, Set<Integer>> map;

    public int minTrioDegree(int n, int[][] edges) {
    	map = new HashMap<>();
    	for(int i = 1; i <= n; i++){
    		map.put(i, new HashSet<>());
    	}
    	int[] degree = new int[n + 1];
    	for(int[] edge: edges){
    		int left = edge[0];
    		int right = edge[1];
    		map.get(left).add(right);
    		map.get(right).add(left);
    		degree[left] += 1;
    		degree[right] += 1;
    	}
    	boolean have = false;
    	int result = Integer.MAX_VALUE;
    	for(int i = 1; i <= n; i++){
    		for(int j = i + 1; j <= n; j++){
    			for(int k = j + 1; k <= n; k++){
    				if(!connected(i, j, k)){
    					continue;
    				}
    				have = true;
    				result = Math.min(result, degree[i] + degree[j] + degree[k] - 6);
    			}
    		}
    	}
    	return have ? result : -1;
    }

    private boolean connected(int x, int y, int z){
    	return map.get(x).contains(y) && map.get(x).contains(z) && map.get(y).contains(z);
    }
}