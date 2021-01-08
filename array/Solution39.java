import java.util.List;
import java.util.ArrayList;

class Solution39 {
	public List<List<Integer>> combinationSum(int[] candidates, int target) {
		List<List<Integer>> ans = new ArrayList<List<Integer>>();
		List<Integer> combine = new ArrayList<Integer>();
		dfs(candidates, target, ans, combine, 0);
		return ans;
	}

	public void dfs(int[] candidates, int target, List<List<Integer>> ans, List<Integer> combine, int idx) {
		if (idx == candidates.length) {
			return;
		}
		if (target == 0) {
			ans.add(new ArrayList<Integer>(combine));
			return;
		}
		// 直接跳过
		dfs(candidates, target, ans, combine, idx + 1);
		// 选择当前数
		if (target - candidates[idx] >= 0) {
			combine.add(candidates[idx]);
			dfs(candidates, target - candidates[idx], ans, combine, idx);
			combine.remove(combine.size() - 1);
		}
	}


    public static void main(String[] args){
    	Solution39 s = new Solution39();
    	int[] test1 = new int[]{3, 5, 8};
    	List<List<Integer>> result = s.combinationSum(test1, 11);
    	for(List<Integer> ele: result){
    		System.out.println(ele);
    	}
    }
}