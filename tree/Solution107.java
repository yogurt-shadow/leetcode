package  tree;

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

import java.util.List;
import java.util.LinkedList;
class Solution107 {

    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        return inverse(levelOrder(root));
    }
    public List<List<Integer>> levelOrder(TreeNode root) {
    	List<List<Integer>> result = new LinkedList<>();
    	if(root == null){
    		return result;
    	}
		List<Integer> temp = new LinkedList<>();
    	temp.add(root.val);
    	result.add(temp);

    	List<List<Integer>> left = levelOrder(root.left);
    	List<List<Integer>> right = levelOrder(root.right);
    	List<List<Integer>> connect = connect(left, right);
    	for(List<Integer> ele: connect){
    		result.add(ele);
    	}
    	return result;
    	}

   	private int max(int a, int b){
   		if(a > b){
   			return a;
   		}
   		return b;
   	}

    private List<List<Integer>> inverse(List<List<Integer>> result){
        List<List<Integer>> output = new LinkedList<>();
        for(int i = result.size() - 1; i >= 0; i--){
            output.add(result.get(i));
        }
        return output;
    }

    private List<List<Integer>> connect(List<List<Integer>> left, List<List<Integer>> right){
    	List<List<Integer>> result = new LinkedList<>();
    	for(int i = 0; i < max(left.size(), right.size()); i++){
    		List<Integer> current = new LinkedList<>();

    		if(i >= left.size()){
    			for(Integer ele: right.get(i)){
    				current.add(ele);
    			}
    		}

    		else if(i >= right.size()){
    			for(Integer ele: left.get(i)){
    				current.add(ele);
    			}
    		}

    		else{
    			for(Integer ele: left.get(i)){
    				current.add(ele);
    			}
    			for(Integer ele: right.get(i)){
    				current.add(ele);
    			}
    		}
    		result.add(current);
    	}
    	return result;
    }
}