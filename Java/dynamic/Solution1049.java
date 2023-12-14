class Solution1049 {
    public int lastStoneWeightII(int[] stones) {
    	int sum = 0;
    	int number = stones.length;
    	for(int ele: stones){
    		sum += ele;
    	}
    	int[] dp = new int[sum / 2 + 1];
    	for(int i = 1; i <= number; i++){
    		for(int j = dp.length - 1; j >= stones[i - 1]; j--){
    			dp[j] = Math.max(dp[j], dp[j - stones[i - 1]] + stones[i - 1]);
    		}
    	}
    	return sum - 2 * dp[dp.length - 1];
    }

    public static void main(String[] args){
    	Solution1049 s = new Solution1049();
    	int[] stones = {2, 4, 1, 1};
    	System.out.println(s.lastStoneWeightII(stones));
    }
}