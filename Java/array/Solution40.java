import java.util.List;
import java.util.LinkedList;
import java.util.Arrays;

class Solution40 {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
    	List<List<Integer>> result = new LinkedList<>();
    	if(candidates.length == 0){
    		return result;
    	}

    	for(int i = 0; i < candidates.length; i++){
            if(i != 0 && candidates[i] == candidates[i - 1]){
                continue;
            }
    		if(candidates[i] == target){
    			List<Integer> cur = new LinkedList<>();
    			cur.add(target);
    			result.add(cur);
    		}

    		else if(candidates[i] < target){
    			int[] other = new int[candidates.length - i - 1];
    			System.arraycopy(candidates, i + 1, other, 0, candidates.length - i - 1);
    			List<List<Integer>> list = combinationSum2(other, target - candidates[i]);
    			for(List<Integer> ele: list){
    				ele.add(candidates[i]);
    				result.add(ele);
    			}
    		}
    	}
    	return result;
    }

    public static void main(String[] args){
    	Solution40 s = new Solution40();
    	int[] test1 = new int[]{2, 5, 2, 1, 2};
    	List<List<Integer>> result = s.combinationSum2(test1, 5);
    	for(List<Integer> ele: result){
    		System.out.println(ele);
    	}
    }
}