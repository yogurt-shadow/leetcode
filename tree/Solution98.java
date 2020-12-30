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
class Solution98 {
    public boolean isValidBST(TreeNode root) {
    	return range(root.left, Long.MIN_VALUE, (long) root.val) && range(root.right, (long) root.val, Long.MAX_VALUE);
    }

    private boolean range(TreeNode x, long min, long max){
    	if(x == null){
    		return true;
    	}

    	if(!(x.val > min && x.val < max)){
    		return false;
    	}

    	return range(x.left, min, (long) x.val) && range(x.right, (long) x.val, max);
    }
}