package tree;
import java.util.List;
import java.util.LinkedList;

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution226 {
    public TreeNode invertTree(TreeNode root) {
    	if(root == null){
    		return root;
    	}

    	TreeNode left = invertTree(root.left);
    	TreeNode right = invertTree(root.right);
    	return new TreeNode(root.val, right, left);
    }
}