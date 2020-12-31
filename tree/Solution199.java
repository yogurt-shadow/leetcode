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
class Solution199 {
    public List<Integer> rightSideView(TreeNode root) {
    	List<List<Integer>> list = new LinkedList<>();
    	add(list, root, 1);

    	List<Integer> result = new LinkedList<>();
    	for(List<Integer> ele: list){
    		result.add(ele.get(ele.size() - 1));
    	}

    	return result;
    }

    private void add(List<List<Integer>> list, TreeNode root, int level){
    	if(root == null){
    		return;
    	}

    	if(list.size() < level){
    		list.add(new LinkedList<Integer>());
    	}

    	list.get(level - 1).add(root.val);
    	add(list, root.left, level + 1);
    	add(list, root.right, level + 1);
    }


    
}