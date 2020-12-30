/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

class Solution101 {
    public boolean isSymmetric(TreeNode root) {
        if(root == null){
        	return true;
        }

        return isSymmetric(root.left, root.right);
    }

    private boolean isSymmetric(TreeNode left, TreeNode right){
    	if(left == null){
    		return right == null;
    	}
    	if(right == null){
    		return left == null;
    	}
    	if(left.val != right.val){
    		return false;
    	}

    	return isSymmetric(left.left, right.right) && isSymmetric(left.right, right.left);
    }
}