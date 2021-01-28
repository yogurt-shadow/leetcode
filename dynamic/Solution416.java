class Solution416 {
    public boolean canPartition(int[] nums) {
    	int sum = 0;
    	int number = nums.length;
    	for(int ele: nums){
    		sum += ele;
    	}
    	if(sum % 2 != 0){
    		return false;
    	}
    	int total = sum / 2;
    	int[] dp = new int[total + 1];
    	for(int i = 1; i <= number; i++){
    		for(int j = total; j >= nums[i - 1]; j--){
    			dp[j] = Math.max(dp[j], dp[j - nums[i - 1]] + nums[i - 1]);
    		}
    	}
    	return dp[total] == total;
    }
}