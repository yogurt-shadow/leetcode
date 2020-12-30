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
class Solution102 {
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

    public static void main(String[] args){
        /**
    	List<Integer> a = new LinkedList<>();
    	a.add(1);
    	a.add(2);

    	List<Integer> b = new LinkedList<>();
    	b.add(3);
   
    	List<List<Integer>> left = new LinkedList<>();
    	left.add(a);
    	left.add(b);

    	List<List<Integer>> right = new LinkedList<>();

    	right.add(a);

    	Solution102 s = new Solution102();
    	List<List<Integer>> result = s.connect(left, right);

    	for(List<Integer> ele: result){
    		for(Integer x: ele){
    			System.out.print(x + " ");
    		}
    		System.out.println();
    	}
        */

        TreeNode x = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
        Solution102 s = new Solution102();
        List<List<Integer>> result = s.levelOrder(x);

        for(List<Integer> ele: result){
            for(Integer cc: ele){
                System.out.print(cc + " ");
            }
            System.out.println();
        }

    }
}