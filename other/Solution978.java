class Solution978 {
    public int maxTurbulenceSize(int[] arr) {
    	int length = arr.length;
    	if(length == 1){
    		return 1;
    	}
    	int[][] dp = new int[length][2];
    	for(int i = 0; i < length; i++){
    		dp[i][0] = 1;
    		dp[i][1] = 1;
    	}
    	int max = 1;
    	for(int i = 1; i < length; i++){
    		if(arr[i] > arr[i - 1]){
    			dp[i][1] = dp[i - 1][0] + 1;
    			max = Math.max(max, dp[i][1]);
    		}
    		else if(arr[i] < arr[i - 1]){
    			dp[i][0] = dp[i - 1][1] + 1;
    			max = Math.max(max, dp[i][0]);	
    		}
    	}
    	return max;
    }

}