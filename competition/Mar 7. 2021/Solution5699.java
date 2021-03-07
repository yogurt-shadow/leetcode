import java.util.*;

class Solution5699 {
	int[] dist;
	int size;
	Map<Integer, List<int[]>> map;
    long[] mem;
    final int mod = 1000000000 + 7;

    public int countRestrictedPaths(int n, int[][] edges) {
    	size = n;
    	dist = new int[n + 1];
        mem = new long[n + 1];
        Arrays.fill(mem, -1);
    	Arrays.fill(dist, Integer.MAX_VALUE);
    	map = new HashMap<>();
    	for(int i = 1; i <= n; i++){
    		map.put(i, new LinkedList<>());
    	}
    	for(int[] edge: edges){
    		map.get(edge[0]).add(new int[]{edge[1], edge[2]});
    		map.get(edge[1]).add(new int[]{edge[0], edge[2]});
    	}
    	findshortest(n);
        int res = (int) findpaths(1, n);
        return res;
    }

    private long findpaths(int start, int end){
        if(start == end){
            return 1;
        }
        if(mem[start] != -1){
            return mem[start];
        }
        int count = 0;
        for(int[] ele: map.get(start)){
            int point = ele[0];
            if(dist[point] < dist[start]){
                count += findpaths(point, end);
                count = count % mod;
            }
        }
        mem[start] = count;
        return count;
    }

    private void findshortest(int start){
    	boolean[] visit = new boolean[size + 1];
    	dist[start] = 0;
		Comparator<Integer> cmp = (x, y) -> dist[x] - dist[y];
		PriorityQueue<Integer> pq = new PriorityQueue<>(cmp);
    	pq.offer(start);
        while(!pq.isEmpty()){
            int cur = pq.poll();
            if(visit[cur]){
                continue;
            }
            visit[cur] = true;
            for(int[] ele: map.get(cur)){
                int point = ele[0];
                dist[point] = Math.min(dist[point], dist[cur] + ele[1]);
                pq.add(point);
            }
        }
    }

    public static void main(String[] args){
    	Solution5699 s = new Solution5699();
    	int[][] edges = {{1,2,3},{1,3,3},{2,3,1},{1,4,2},{5,2,2},{3,5,1},{5,4,10}};
        s.countRestrictedPaths(5, edges);
        int[] dis = s.dist;
        for(int i = 1; i <= 5; i++){
            System.out.println(dis[i]);
        }
	}
}