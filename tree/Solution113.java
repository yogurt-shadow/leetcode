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
class Solution113 {
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
    	List<List<Integer>> result = new LinkedList<>();
    	if(root == null){
    		return result;
    	}

    	if(root.left == null && root.right == null && root.val == sum){
    		List<Integer> current = new LinkedList<>();
    		current.add(root.val);
    		result.add(current);
    		return result;
    	}

    	List<List<Integer>> xxx = connect(pathSum(root.left, sum - root.val), pathSum(root.right, sum - root.val));
    	for(List<Integer> ele: xxx){
			((LinkedList<Integer>) ele).addFirst(root.val);
    	}

    	return xxx;
    }

    private List<List<Integer>> connect(List<List<Integer>> list1, List<List<Integer>> list2){
    	List<List<Integer>> result = new LinkedList<>();
    	
    	for(List<Integer> ele: list1){
    		result.add(ele);
    	}


    	for(List<Integer> ele: list2){
    		result.add(ele);
    	}

    	return result;
    }
}