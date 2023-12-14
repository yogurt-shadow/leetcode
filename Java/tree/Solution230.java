package tree;

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
class Solution230 {
    public int kthSmallest(TreeNode root, int k) {
        int left_size = size(root.left);
        if(k <= left_size){
        	return kthSmallest(root.left, k);
        }

        if(k == left_size + 1){
        	return root.val;
        }

        else{
        	return kthSmallest(root.right, k - left_size - 1);
        }
    }

    private int size(TreeNode root){
    	if(root == null){
    		return 0;
    	}
    	return size(root.left) + size(root.right) + 1;
    }
}