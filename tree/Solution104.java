/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution104 {
    public int maxDepth(TreeNode root) {
    	if(root == null){
    		return 0;
    	}

    	return max(maxDepth(root.left), maxDepth(root.right)) + 1;
    }

    private int max(int a, int b){
    	if(a > b){
    		return a;
    	}
    	return b;
    }

    public static void main(String[] args){
    	TreeNode x = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
        Solution104 s  = new Solution104();
        System.out.println(s.maxDepth(x));
    }
}