class Solution53 {
    public int maxSubArray(int[] nums) {
    	int sum = 0;
    	int max = Integer.MIN_VALUE;
    	for(int ele: nums){
    		sum += ele;
            max = Math.max(max, sum);
            sum = Math.max(sum, 0);
    	}
    	return max;
    }

    public static void main(String[] args){
    	Solution53 s = new Solution53();
    	int[] test = new int[]{-2,-1};
    	System.out.println(s.maxSubArray(test));
    }
}