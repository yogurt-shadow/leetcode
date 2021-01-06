import java.util.Arrays;

class Solution31 {
    public void nextPermutation(int[] nums) {
    	if(nums.length < 2){
    		return;
    	}
    	for(int i = nums.length - 1; i > 0; i--){
    		if(nums[i - 1] < nums[i]){
    			int temp = nums[i - 1];
    			nums[i - 1] = nums[i];
    			nums[i] = temp;
    			return;
    		}
    	}
    	Arrays.sort(nums);
    }
}