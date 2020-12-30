/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution105 {
    public TreeNode buildTree(int[] preorder, int[] inorder) {
    	if(preorder.length == 1){
    		return new TreeNode(preorder[0]);
    	}

    	if(preorder.length == 0){
    		return null;
    	}

    	int root = preorder[0];
    	int index = find(inorder, root);
    	int[] left_inorder = new int[index];
    	int[] left_preorder = new int[index];
    	System.arraycopy(inorder, 0, left_inorder, 0, index);
    	System.arraycopy(preorder, 1, left_preorder, 0, index);

    	int[] right_inorder = new int[inorder.length - 1 - index];
    	int[] right_preorder = new int[right_inorder.length];
    	System.arraycopy(inorder, index + 1, right_inorder, 0, inorder.length - 1 - index);
    	System.arraycopy(preorder, 1 + index, right_preorder, 0, inorder.length - 1 - index);

    	return new TreeNode(root, buildTree(left_preorder, left_inorder), buildTree(right_preorder, right_inorder));

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
    	int[] preorder = new int[]{3,9,20,15,7};
    	int[] inorder = new int[]{9,3,15,20,7};
    	
        Solution105 s  = new Solution105();
        TreeNode x = s.buildTree(preorder, inorder);
        System.out.println(x.val);
        System.out.println(x.left.val);
        System.out.println(x.right.val);
        System.out.println(x.right.left.val);
        System.out.println(x.right.right.val);

    }
}