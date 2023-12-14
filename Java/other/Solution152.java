class Solution152 {
    public int maxProduct(int[] nums) {
    	int length = nums.length;
    	int[] max = new int[length];
    	int[] min = new int[length];
    	max[0] = nums[0];
    	min[0] = nums[0];
    	for(int i = 1; i < length; i++){
    		max[i] = Math.max(nums[i], Math.max(nums[i] * max[i - 1], nums[i] * min[i - 1]));
    		min[i] = Math.min(nums[i], Math.min(nums[i] * max[i - 1], nums[i] * min[i - 1]));
    	}
    	int result = Integer.MIN_VALUE;
    	for(int ele: max){
    		result = Math.max(result, ele);
    	}
    	return result;
    }
}