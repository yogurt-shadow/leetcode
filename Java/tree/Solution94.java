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

import java.util.List;
import java.util.LinkedList;

public class Solution94 {

	private static class TreeNode{
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

	public List<Integer> inorderTraversal(TreeNode root) {
       List<Integer> result = new LinkedList<>();
       if(root == null){
       	return result;
       }

       if(root.left != null){
       	connect(result, inorderTraversal(root.left));
       }
       result.add(root.val);
       if(root.right != null){
       	connect(result, inorderTraversal(root.right));
       }

       return result;

    }

    private void connect(List<Integer> list1, List<Integer> list2){
    	for(Integer current: list2){
    		list1.add(current);
    	}
    }

   
}