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
class Solution257 {
    public List<String> binaryTreePaths(TreeNode root) {
    	List<String> result = new LinkedList<>();
    	if(root == null){
    		return result;
    	}

    	if(root.left == null && root.right == null){
    		result.add(Integer.toString(root.val));
    		return result;
    	}

    	List<String> left = binaryTreePaths(root.left);
    	List<String> right = binaryTreePaths(root.right);
    	for(String ele: left){
    		result.add(Integer.toString(root.val) + "->" + ele);
    	}

    	for(String ele: right){
    		result.add(Integer.toString(root.val)  + "->"+ ele);
    	}

    	return result;

    }
}