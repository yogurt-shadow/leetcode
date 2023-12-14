class Solution121 {
    public int maxProfit(int[] prices) {
    	if(prices.length == 1){
    		return 0;
    	}
    	int max = 0;
    	int[] min = new int[prices.length];
    	min[0] = prices[0];
    	int[] sell = new int[prices.length];
    	sell[0] = 0;
    	for(int i = 1; i < prices.length; i++){
    		sell[i] = Math.max(sell[i - 1], prices[i] - min[i - 1]);
    		min[i] = Math.min(min[i - 1], prices[i]);
    	}
    	return sell[prices.length - 1];
    }
}