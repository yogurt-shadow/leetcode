/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution106 {
    public TreeNode buildTree(int[] inorder, int[] postorder) {
    	if(inorder.length == 0){
    		return null;
    	}

    	if(inorder.length == 1){
    		return new TreeNode(inorder[0]);
    	}

    	int root = postorder[postorder.length - 1];
    	int index = find(inorder, root);
    	int[] left_inorder = new int[index];
    	int[] left_postorder = new int[index];

    	System.arraycopy(inorder, 0, left_inorder, 0, index);
    	System.arraycopy(postorder, 0, left_postorder, 0, index);

    	int[] right_inorder = new int[inorder.length - 1 - index];
    	int[] right_postorder = new int[inorder.length - 1 - index];

    	System.arraycopy(inorder, index + 1, right_inorder, 0, inorder.length - 1 - index);
    	System.arraycopy(postorder, index, right_postorder, 0, inorder.length - 1 - index);

    	return new TreeNode(root, buildTree(left_inorder, left_postorder), buildTree(right_inorder, right_postorder));

    }

     private int find(int[] x, int ele){
    	for(int i = 0; i < x.length; i++){
    		if(x[i] == ele){
    			return i;
    		}
    	}
    	return -1;
    }

     public static void main(String[] args){
    	int[] postorder = new int[]{9, 15, 7, 20, 3};
    	int[] inorder = new int[]{9,3,15,20,7};
    	
        Solution106 s  = new Solution106();
        TreeNode x = s.buildTree(inorder, postorder);
        System.out.println(x.val);
        System.out.println(x.left.val);
        System.out.println(x.right.val);
        System.out.println(x.right.left.val);
        System.out.println(x.right.right.val);

    }
}