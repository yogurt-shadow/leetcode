import java.util.*;

class Solution5670 {
    public int[] getCoprimes(int[] nums, int[][] edges) {
        List<Integer>[] nodes = new List[nums.length];
        for (int i = 0; i < nodes.length; i++) {
            nodes[i] = new ArrayList<>();
        }
        for (int[] edge : edges) {
            nodes[edge[0]].add(edge[1]);
            nodes[edge[1]].add(edge[0]);
        }
        List<Integer> nearest = new ArrayList<>();
        int[] ret = new int[nums.length];
        dfs(nodes, -1, 0, nearest ,ret, nums);
        return ret;
    }

    private void dfs(List<Integer>[] nodes, int from, int to, List<Integer> path, int[] ret, int[] nums) {
        List<Integer> node = nodes[to];
        int idx = -1;
        List<Integer> next_path = new ArrayList<>();
        for (int i : path) {
            if (nums[i] != nums[to]){
                next_path.add(i);
            }
            if (gcd(nums[i], nums[to]) == 1){
                idx = i;
            }
        }
        next_path.add(to);
        ret[to] = idx;
        for (int child : node){
            if (child == from) continue;
            dfs(nodes, to, child, next_path, ret, nums);
        }
    }
    private int gcd(int a, int b){
        if (a < b){
            return gcd(b, a);
        }
        while (b > 0){
            int t = a % b;
            a = b;
            b = t;
        }
        return a;
    }

    public static void main(String[] args){
    	Solution5670 s = new Solution5670();
    	int[] test1 = {5,6,10,2,3,6,15};
		int[][] test2 = {{0,1},{0,2},{1,3},{1,4},{2,5},{2,6}};
		int[] result = s.getCoprimes(test1, test2);
    }
}