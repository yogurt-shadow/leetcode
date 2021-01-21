import java.util.List;
import java.util.LinkedList;
import java.util.Arrays;
import java.util.Comparator;

class Solution1489 {
    public List<List<Integer>> findCriticalAndPseudoCriticalEdges(int n, int[][] edges) {
    	int[][] copy = new int[edges.length][edges[0].length];
    	for(int i = 0; i < edges.length; i++){
    		for(int j = 0; j < 3; j++){
    			copy[i][j] = edges[i][j];
    		}
    	}

    	Comparator<int[]> cmp = (x, y) -> x[2] - y[2];
    	Arrays.sort(edges, cmp);
    	UnionFind uf = new UnionFind(n);
    	int value = 0;
    	for(int[] edge: edges){
    		if(!uf.is_connected(edge[0], edge[1])){
    			uf.connect(edge[0], edge[1]);
    			value += edge[2];
    		}
    	}
    	List<List<Integer>> result = new LinkedList<>();
    	result.add(new LinkedList<>());
    	result.add(new LinkedList<>());

    	for(int i = 0; i < edges.length; i++){
    		UnionFind uf2 = new UnionFind(n);
    		int value2 = 0;
    		for(int j = 0; j < edges.length; j++){
    			if(j == i){
    				continue;
    			}
    			if(!uf2.is_connected(edges[j][0], edges[j][1])){
    				uf2.connect(edges[j][0], edges[j][1]);
    				value2 += edges[j][2];
    			}
    		}
    		if(value2 != value){
    			result.get(0).add(i);
    		}
    	}

    	for(int j = 0; j < edges.length; j++){
    		if(result.get(0).contains(j)){
    			continue;
    		}
  			UnionFind uf2 = new UnionFind(n);
  			int value2 = 0;
  			uf2.connect(edges[j][0], edges[j][1]);
  			value2 += edges[j][2];
  			for(int k = 0; k < edges.length; k++){
  				if(k == j){
  					continue;
  				}
  				if(!uf2.is_connected(edges[k][0], edges[k][1])){
  					uf2.connect(edges[k][0], edges[k][1]);
  					value2 += edges[k][2];
  				}
  			}
  			if(value2 == value){
  				result.get(1).add(j);
  			}
    	}
    	List<List<Integer>> result2 = new LinkedList<>();
    	result2.add(new LinkedList<>());
    	result2.add(new LinkedList<>());
    	for(int i = 0; i < 2; i++){
    		List<Integer> list = result.get(i);
    		for(int index = 0; index < list.size(); index++){
    			result2.get(i).add(convert(list.get(index), edges, copy));
    		}
    	}
    	return result2;
    }

    private int convert(int x, int[][] edges, int[][] copy){
    	int[] edge = edges[x];
    	for(int i = 0; i < copy.length; i++){
    		if(copy[i][0] == edge[0] && copy[i][1] == edge[1] && copy[i][2] == edge[2]){
    			return i;
    		}
    	}
    	return -1;
    }

    public static void main(String[] args){
    	Solution1489 s = new Solution1489();
    	int[][] edges = new int[][]{new int[]{0, 1, 1}, new int[]{1, 2, 1}, new int[]{0, 2, 1}, new int[]{2, 3, 4},
    								new int[]{3, 4, 2}, new int[]{3, 5, 2}, new int[]{4, 5, 2}};
    	List<List<Integer>> result = s.findCriticalAndPseudoCriticalEdges(6, edges);
    	System.out.println(result.get(0));
    	System.out.println(result.get(1));
    }
}