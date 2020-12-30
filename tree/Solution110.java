package  tree;

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
class Solution110 {
    public boolean isBalanced(TreeNode root) {
    	if(root == null){
    		return true;
    	}

    	return range(depth(root.left), depth(root.right)) && isBalanced(root.left) && isBalanced(root.right);
    }

    private int depth(TreeNode x){
    	if(x == null){
    		return 0;
    	}

    	return Math.max(depth(x.left), depth(x.right)) + 1;
    }

    private boolean range(int x, int y){
    	return Math.abs(x - y) <= 1;
    }

    public static void main(String[] args){
    	TreeNode root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    	Solution110 s = new Solution110();
    	System.out.println(s.isBalanced(root));


    }
}