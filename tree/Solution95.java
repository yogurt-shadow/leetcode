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

import com.sun.source.tree.Tree;

import java.util.List;
import java.util.LinkedList;
public class Solution95 {
	public List<TreeNode> generateTrees(int n) {
		if(n < 1){
			return new LinkedList<TreeNode>();
		}

    	return generateTrees(1, n);    
    }

    private List<TreeNode> generateTrees(int start, int end){
    	List<TreeNode> result = new LinkedList<>();

    	for(int i = start; i <= end; i++){
    		connect(result, generate_root(start, end, i));
    	}
    	return result;
    }

    private void connect(List<TreeNode> list1, List<TreeNode> list2){
    	for(TreeNode node: list2){
    		list1.add(node);
    	}

    }

    private List<TreeNode> generate_root(int start, int end, int root){
    	List<TreeNode> result = new LinkedList<>();
        if(start == end){
            result.add(new TreeNode(root));
            return result;
        }
    	if(root == start){
    		for(TreeNode right: generateTrees(root + 1, end)){
    			result.add(new TreeNode(root, null, right));
    		}
    		return result;
    	}

    	if(root == end){
    		for(TreeNode left: generateTrees(start, root - 1)){
    			result.add(new TreeNode(root, left, null));
    		}
    		return result;
    	}

    	for(TreeNode left: generateTrees(start, root - 1)){
    		for(TreeNode right: generateTrees(root + 1, end)){
    			result.add(new TreeNode(root, left, right));
    		}

    	}

    	return result;

    }

    public static void main(String[] args){
		Solution95 s = new Solution95();
		List<TreeNode> test = s.generateTrees(3);

	}
}
