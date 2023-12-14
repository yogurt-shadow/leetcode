import java.util.*;

class Solution228 {
    public List<String> summaryRanges(int[] nums) {
    	List<String> result = new ArrayList<>();
    	for(int i = 0; i < nums.length; i++){
    		int j = i;
    		while(i + 1 < nums.length && nums[i + 1] == nums[i] + 1){
    			i += 1;
    		}
    		
    		if(i == j){
    			result.add(String.valueOf(nums[i]));
    		}
    		else{
    			result.add(nums[j] + "->" + nums[i]);
    		}
    		
    	}
    	return result;
    }

    public static void main(String[] args){
    	Solution228 s = new Solution228();
    	int[] test1 = new int[]{0,1,2,4,5,7};
    	System.out.println(s.summaryRanges(test1));
    }
}