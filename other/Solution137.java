import java.util.Arrays;

class Solution137 {
    public int singleNumber(int[] nums) {
    	Arrays.sort(nums);
    	for(int i = 0; i < nums.length; i++){
    		if(i + 1 == nums.length || nums[i] != nums[i + 1]){
    			return nums[i];
    		}
    		i = i + 2;
    	}
    	return -1;
    }
}