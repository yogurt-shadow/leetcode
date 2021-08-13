import java.util.*;

class Solution743 {
    final static int MAX = 0x3f3f3f3f;

    private Map<Integer, Map<Integer, Integer>> mp;
    private PriorityQueue<int[]> pq;
    private int[] visited;
    private int[] dist;

    public int networkDelayTime(int[][] times, int n, int k) {
        visited = new int[n + 1];
        dist = new int[n + 1];
        for(int i = 0; i <= n; i++){
            dist[i] = MAX;
        }
        dist[k] = 0;
        mp = new HashMap<>();
        for(int[] ele: times){
            if(!mp.containsKey(ele[0])){
                mp.put(ele[0], new HashMap<>());
            }
            mp.get(ele[0]).put(ele[1], ele[2]);
        }
        pq = new PriorityQueue<>(
            new Comparator<>(){
                @Override
                public int compare(int[] x, int[] y){
                    return x[0] - y[0];
                }
            }
        );
        pq.add(new int[]{0, k});
        while(!pq.isEmpty()){
            int[] cur = pq.poll();
            if(visited[cur[1]] == 1){
                continue;
            }
            visited[cur[1]] = 1;
            if(!mp.containsKey(cur[1])){
                continue;
            }
            for(Integer neighbor : mp.get(cur[1]).keySet()){
                dist[neighbor] = Math.min(dist[neighbor], dist[cur[1]] + mp.get(cur[1]).get(neighbor));
                pq.add(new int[]{dist[neighbor], neighbor});
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(dist[i] == MAX){
                return -1;
            }
            ans = Math.max(ans, dist[i]);
        }
        return ans;
    }
}