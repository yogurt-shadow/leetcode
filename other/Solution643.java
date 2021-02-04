class Solution643 {
    public double findMaxAverage(int[] nums, int k) {
    	int left = 0;
    	int right = k - 1;
    	int sum = 0;
    	for(int i = 0; i <= right; i++){
    		sum += nums[i];
    	}
    	int max = sum;
    	while(right < nums.length - 1){
    		right += 1;
    		sum += nums[right];
    		sum -= nums[left];
    		max = Math.max(max, sum);
            left += 1;
    	}
    	return max * 1.0 / k;
    }
}
