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
class Solution114 {
    public void flatten(TreeNode root) {
        if(root == null){
            return;
        }
        List<Integer> collect = collect(root);
        root.left = null;

        TreeNode x = root;
        for(int i = 1; i < collect.size(); i++){
        	x.right = new TreeNode(collect.get(i));
        	x = x.right;
        }
    }

    private List<Integer> collect(TreeNode root){
    	List<Integer> result = new LinkedList<>();
    	if(root == null){
    		return result;
    	}
    	result.add(root.val);
    	connect(result, collect(root.left), collect(root.right));
    	return result;
    }

    private void connect(List<Integer> list1, List<Integer> list2, List<Integer> list3){
    	for(Integer ele: list2){
    		list1.add(ele);
    	}

    	for(Integer ele: list3){
    		list1.add(ele);
    	}
    }

    public static void main(String[] args){
    	Solution114 s = new Solution114();
    	TreeNode root = new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)), new TreeNode(5, null, new TreeNode(6)));
    	for(Integer ele: s.collect(root)){
    		System.out.println(ele);
    	}
    }
}