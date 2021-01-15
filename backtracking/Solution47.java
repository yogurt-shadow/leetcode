import java.util.List;
import java.util.LinkedList;
import java.util.Set;
import java.util.HashSet;

class Solution47 {
    public List<List<Integer>> permuteUnique(int[] nums) {
    	List<List<Integer>> result = new LinkedList<>();
    	List<Integer> list = new LinkedList<>();
    	Set<Integer> set = new HashSet<>();
    	put(result, list, nums, set);
    	return result;
    }

    private void put(List<List<Integer>> result, List<Integer> list, int[] nums, Set<Integer> set2){
    	Set<Integer> set = new HashSet<>();
    	for(int i = 0; i < nums.length; i++){
    		if(set2.contains(i) || set.contains(nums[i])){
    			continue;
    		}
    		set.add(nums[i]);
    		list.add(nums[i]);
    		set2.add(i);
    		if(list.size() == nums.length){
    			List<Integer> copy = new LinkedList<>(list);
    			result.add(copy);
    			list.remove(list.size() - 1);
    			set2.remove(i);
    			return;
    		}
    		put(result, list, nums, set2);
    		set2.remove(i);
    		list.remove(list.size() - 1);
    	}
    }

    public static void main(String[] args){
    	Solution47 s = new Solution47();
    	int[] test1 = new int[]{1, 1, 2};
    	List<List<Integer>> result = s.permuteUnique(test1);
    }
}