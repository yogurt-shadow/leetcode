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
class Solution222 {
    public int countNodes(TreeNode root) {
    	int level = level(root, -1);
    	if(level == -1){
    		return 0;
    	}

    	List<Integer> level_num = new LinkedList<>();
    	level_add(level_num, root, 0, level);
    	return level_num.size() + (int) Math.pow(2, level) - 1;
    }

    private int level(TreeNode root, int x){
    	if(root == null){
    		return x;
    	}

    	return level(root.left, x + 1);
    }

    private void level_add(List<Integer> list, TreeNode root, int current, int level){
    	if(current == level){
    		if(root != null){
    		list.add(root.val);
    	}
    	}

    	else{
    		level_add(list, root.left, current + 1, level);
    		level_add(list, root.right, current + 1, level);
    	}
    }

    public static void main(String[] args){
    	TreeNode root = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3, new TreeNode(6), null));
    	Solution222 s = new Solution222();
		List<Integer> level_num = new LinkedList<>();
		int level = s.level(root, -1);
    	s.level_add(level_num, root, 0, level);
    	for(Integer ele: level_num){
    		System.out.println(ele);
    	}
    }
}