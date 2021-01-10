import java.util.List;
import java.util.LinkedList;
import java.util.Arrays;

class Solution15 {
    public List<List<Integer>> threeSum(int[] nums) {
    	List<List<Integer>> result = new LinkedList<>();
    	Arrays.sort(nums);
    	for(int i = 0; i < nums.length; i++){
    		if(i != 0 && nums[i] == nums[i - 1]){
    			continue;
    		}
            int target = -nums[i];
    		for(int j = i + 1; j < nums.length - 1; j++){
    			if(j != i + 1 && nums[j - 1] == nums[j]){
    				continue;
    			}
    			int point = nums.length - 1;
    			while(nums[point] + nums[j] > target && point > j + 1){
    				point -= 1;
    			}
    			if(nums[j] + nums[point] == target){
    				List<Integer> cur = new LinkedList<>();
    				cur.add(nums[i]);
    				cur.add(nums[j]);
    				cur.add(nums[point]);
    				result.add(cur);
    			}
    		}
    	}
    	return result;
    }

    public static void main(String[] args){
    	Solution15 s = new Solution15();
    	int[] test = new int[]{-1,0,1,2,-1,-4};
    	List<List<Integer>> result = s.threeSum(test);
    }
}