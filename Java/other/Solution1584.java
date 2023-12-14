import java.util.Map;
import java.util.HashMap;
import java.util.List;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;

class Solution1584 {
    public int minCostConnectPoints(int[][] points) {
    	Map<Integer, List<int[]>> map = new HashMap<>();
    	Queue<Integer> pq = new PriorityQueue<>();
    	for(int i = 0; i < points.length; i++){
    		for(int j = 0; j < i; j++){
    			int distance = manhatten(points[i], points[j]);
    			if(!map.containsKey(distance)){
    				map.put(distance, new LinkedList<>());
    			}
    			map.get(distance).add(new int[]{i, j});
    			pq.add(distance);
    		}
    	}
    	int edge = 0;
    	int cost = 0;
    	UnionFind uf = new UnionFind(points.length);
    	while(edge < points.length - 1){
    		int cur = pq.poll();
    		for(int[] ele: map.get(cur)){
    			int left = ele[0];
    			int right = ele[1];
    			if(uf.is_connected(left, right)){
    				continue;
    			}
    			uf.connect(left, right);
    			edge += 1;
    			cost += cur;
    		}
    	}
    	return cost;
    }

    private int manhatten(int[] point1, int[] point2){
    	return Math.abs(point1[0] - point2[0]) + Math.abs(point1[1] - point2[1]);
    }

    public static void main(String[] args){
    	Solution1584 s = new Solution1584();
    	int[][] points1 = {{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
    	System.out.println(s.minCostConnectPoints(points1));
    }
}