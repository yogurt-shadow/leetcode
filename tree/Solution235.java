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

class Solution235 {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
    	if((p.val - root.val) * (q.val - root.val) <= 0){
    		return root;
    	}

    	if(p.val < root.val && q.val < root.val){
    		return lowestCommonAncestor(root.left, p, q);
    	}

    	else{
    		return lowestCommonAncestor(root.right, p, q);
    	}
     }
}