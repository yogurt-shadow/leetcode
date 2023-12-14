class Solution343 {
    public int integerBreak(int n) {
    	if(n <= 2){
    		return 1;
    	}
    	int[] dp = new int[n + 1];
    	dp[1] = 1;
    	dp[2] = 1;
    	for(int i = 3; i <= n; i++){
    		int max = -1;
    		for(int j = 1; j < i; j++){
    			int cur = Math.max(dp[j], j) * Math.max(dp[i - j], i - j);
    			max = Math.max(max, cur);
    		}
    		dp[i] = max;
    	}
    	return dp[n];
    }

    public static void main(String[] args){
    	Solution343 s = new Solution343();
    	System.out.println(s.integerBreak(4));
    }
}