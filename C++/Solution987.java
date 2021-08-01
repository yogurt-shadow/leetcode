import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
      this.val = val;
      this.left = left;
      this.right = right;
    }
}
 


class Solution987 {
    private PriorityQueue<int[]> pq;

    public List<List<Integer>> verticalTraversal(TreeNode root) {
        pq = new PriorityQueue<>(new Comparator<>(){
            @Override
            public int compare(int[] x, int[] y){
                for(int i = 0; i < 3; i++){
                    if(x[i] != y[i]){
                        return x[i] - y[i];
                    }
                }
                return -1;
            }
        }
        );
        dfs(root, 0, 0);
        List<List<Integer>> ans = new LinkedList<>();
        List<Integer> list = new LinkedList<>();
        if(root == null){
            return ans;
        }
        int col = pq.peek()[0];
        while(!pq.isEmpty()){
            int[] cur = pq.poll();
            if(cur[0] == col){
                list.add(cur[2]);
            }
            else{
                ans.add(list);
                list = new LinkedList<>();
                list.add(cur[2]);
                col = cur[0];
            }
        }
        ans.add(list);
        return ans;
    }

    private void dfs(TreeNode root, int row, int col){
        if(root == null){
            return;
        }
        pq.offer(new int[]{col, row, root.val});
        dfs(root.left, row + 1, col - 1);
        dfs(root.right, row + 1, col + 1);
    }
}