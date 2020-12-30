/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution108 {
    public TreeNode sortedArrayToBST(int[] nums) {
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