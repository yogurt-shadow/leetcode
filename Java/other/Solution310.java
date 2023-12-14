import java.util.List;
import java.util.LinkedList;
import java.util.Queue;

class Solution310 {
	private List<List<Integer>> list;
    private int[] degree;

    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
    	list = new LinkedList<>();
        List<Integer> result = new LinkedList<>();
        if(n == 1){
            result.add(0);
            return result;
        }
        degree = new int[n];
    	for(int i = 0; i < n; i++){
    		list.add(new LinkedList<>());
    	}
    	for(int[] edge: edges){
    		list.get(edge[0]).add(edge[1]);
    		list.get(edge[1]).add(edge[0]);
            degree[edge[0]] += 1;
            degree[edge[1]] += 1;
    	}

        Queue<Integer> queue = new LinkedList<>();
        for(int i = 0; i < n; i++){
            if(degree[i] == 1){
                queue.add(i);
            }
        }
        while(!queue.isEmpty()){
            int size = queue.size();
            result.clear();
            for(int i = 0; i < size; i++){
                int cur = queue.poll();
                result.add(cur);
                for(Integer ele: list.get(cur)){
                    degree[ele] -= 1;
                    if(degree[ele] == 1){
                        queue.add(ele);
                    }
                }
            }  
        }
    	return result;
    }
}