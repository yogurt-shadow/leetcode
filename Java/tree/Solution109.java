package  tree;

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
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
class Solution109 {
    public TreeNode sortedListToBST(ListNode head) {
        int size = 0;
        int[] input = new int[1000000];
        ListNode x = head;
        while(x != null){
        	input[size] = x.val;
        	size += 1;
        	x = x.next;
        }

        int[] xx = new int[size];
        System.arraycopy(input, 0, xx, 0, size);
        return sortedArrayToBST(xx);
    }


     private TreeNode sortedArrayToBST(int[] nums) {
    	if(nums.length == 0){
    		return null;
    	}

    	if(nums.length == 1){
    		return new TreeNode(nums[0]);
    	}

    	int root = nums[nums.length / 2];
    	int[] left = new int[nums.length / 2];
    	int[] right = new int[nums.length - 1 - nums.length / 2];

    	System.arraycopy(nums, 0, left, 0, nums.length / 2);
    	System.arraycopy(nums, nums.length / 2 + 1, right, 0, nums.length - 1 - nums.length / 2);
    	return new TreeNode(root, sortedArrayToBST(left), sortedArrayToBST(right));
    }
}