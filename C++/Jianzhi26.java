/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Jianzhi26 {
    public boolean isSubStructure(TreeNode A, TreeNode B) {
        if(A == null || B == null){
            return false;
        }
        if(recur(A, B)){
            return true;
        }
        return isSubStructure(A.left, B) || isSubStructure(A.right, B);
    }

    private boolean recur(TreeNode A, TreeNode B){
        if(B == null) return true;
        if(A == null) return false;
        return (A.val == B.val) && recur(A.left, B.left) && recur(A.right, B.right);
    }
}