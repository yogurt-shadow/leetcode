package tree;
import java.util.List;
import java.util.LinkedList;

import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Queue;

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

/** Solution173 */
class BSTIterator {
	Comparator<TreeNode> cmp = new Comparator<>(){
    		public int compare(TreeNode t1, TreeNode t2){
    			return t1.val - t2.val;
    		}
    	};
    Queue<TreeNode> pq;

    public BSTIterator(TreeNode root) {
    	pq = new PriorityQueue<>(cmp);
    	add(root);
    }

    private void add(TreeNode root){
    	if(root == null){
    		return;
    	}
    	pq.add(root);
    	add(root.left);
    	add(root.right);
    }
    
    public int next() {
    	return pq.poll().val;
    }
    
    public boolean hasNext() {
		return pq.size() > 0;
    }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator obj = new BSTIterator(root);
 * int param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */