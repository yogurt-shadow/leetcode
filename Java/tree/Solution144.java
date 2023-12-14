package tree;
import java.util.List;
import java.util.LinkedList;

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
class Solution144 {
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> result = new LinkedList<>();
        if(root == null){
        	return result;
        }
        result.add(root.val);
        connect(result, preorderTraversal(root.left));
        connect(result, preorderTraversal(root.right));
        return result;
    }

    private void connect(List<Integer> list1, List<Integer> list2){
    	for(Integer ele: list2){
    		list1.add(ele);
    	}
    }
}