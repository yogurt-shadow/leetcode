class Solution279 {
    public int numSquares(int n) {
    	int[] dp = new int[n + 1];
    	dp[0] = 0;
    	for(int i = 1; i <= n; i++){
    		int index = 1;
    		int min = Integer.MAX_VALUE;
    		while(i >= index * index){
    			int cur = 1 + dp[i - index * index];
    			min = Math.min(min, cur);
    			index += 1;
    		}
    		dp[i] = min;
    	}
    	return dp[n];
    }

    public static void main(String[] args){
    	Solution279 s = new Solution279();
		System.out.println(s.numSquares(13));
		System.out.println(s.numSquares(12));
    }
}