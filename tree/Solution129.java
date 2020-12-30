package  tree;
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

public class Solution129 {
    public int sumNumbers(TreeNode root) {
    	if(root == null){
    		return 0;
    	}
    	List<List<Integer>> list = numbers(root);
    	return sum(list);
    }

    private List<List<Integer>> numbers(TreeNode root){
    	List<List<Integer>> result = new LinkedList<>();
    	if(root == null){
            List<Integer> cur = new LinkedList<>();
            result.add(cur);
    		return result;
    	}



    	List<List<Integer>> left = numbers(root.left);
    	List<List<Integer>> right = numbers(root.right);
        if(root.left == null && root.right == null){
             List<Integer> cur = new LinkedList<>();
             cur.add(root.val);
            result.add(cur);
            return result;
        }
        if(root.left != null){
		for(List<Integer> ele: left){
			((LinkedList) ele).addFirst(root.val);
			result.add(ele);
		}
    }
        if(root.right != null){
		for(List<Integer> ele: right){
			((LinkedList) ele).addFirst(root.val);
			result.add(ele);
		}
    }

		return result;
    }

    private int sum(List<List<Integer>> list){
    	int sum = 0;
    	for(List<Integer> ele: list){
    		sum += number(ele);
    	}    
    	return sum;
    }

    private int number(List<Integer> ele){
    	int result = 0;
    	for(int i = 0; i < ele.size(); i++){
    		result = result * 10;
    		result += ele.get(i);
    	}
    	return result;
    }

    public static void main(String[] args){
		Solution129 s = new Solution129();
        TreeNode root = new TreeNode(5, new TreeNode(3, new TreeNode(7), new TreeNode(0, new TreeNode(0), null)), new TreeNode(2, new TreeNode(6), null));
        System.out.println(s.sumNumbers(root));
	}
}

