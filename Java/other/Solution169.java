import java.util.Arrays;

class Solution169 {
    public int majorityElement(int[] nums) {
    	Arrays.sort(nums);
    	return nums[nums.length / 2];
    }
}