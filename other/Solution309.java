class Solution309 {
    public int maxProfit(int[] prices) {
        if(prices.length == 0){
            return 0;
        }
    	int days = prices.length;
    	int[][] dp = new int[days][3];
    	dp[0][0] = -prices[0];
    	dp[0][1] = 0; dp[0][2] = 0;
    	for(int i = 1; i < days; i++){
    		dp[i][0] = Math.max(dp[i - 1][0], dp[i - 1][2] - prices[i]);
    		dp[i][1] = dp[i - 1][0] + prices[i];
    		dp[i][2] = Math.max(dp[i - 1][2], dp[i - 1][1]);
    	}
    	return Math.max(dp[days - 1][1], dp[days - 1][2]);
    }
}