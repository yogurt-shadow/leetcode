class Solution5658 {
    public int maxAbsoluteSum(int[] nums) {
    	int size = nums.length;
    	int[] dp1 = new int[size];
    	dp1[0] = Math.max(nums[0], 0);
    	for(int i = 1; i < size; i++){
    		dp1[i] = Math.max(dp1[i - 1] + nums[i], nums[i]);
    	}
    	int[] dp2 = new int[size];
    	dp2[0] = Math.min(nums[0], 0);
    	for(int i = 1; i < size; i++){
    		dp2[i] = Math.min(dp2[i - 1] + nums[i], nums[i]);
    	}
    	int max = 0;
    	for(int i = 0; i < size; i++){
    		max = Math.max(max, Math.max(dp1[i], -dp2[i]));
    	}
    	return max;
    }

    public static void main(String[] args){
    	Solution5658 s = new Solution5658();
    	int[] test = {2,-5,1,-4,3,-2};
    	System.out.println(s.maxAbsoluteSum(test));
    }
}