class Solution5687 {
    public int maximumScore(int[] nums, int[] multipliers) {
    	int n = nums.length;
    	int m = multipliers.length;
		int[][] dp = new int[m + 1][m + 1];
		dp[0][0] = 0;
		for(int left = 1; left <= m; left++){
			dp[left][0] = dp[left - 1][0] + nums[left - 1] * multipliers[left - 1];
		}
		for(int right = 1; right <= m; right++){
			dp[0][right] = dp[0][right - 1] + nums[n - right] * multipliers[right - 1];
		}
		for(int left = 1; left <= m; left++){
			for(int right = 1; left + right <= m; right++){
				int mul = multipliers[left + right - 1];
				dp[left][right] = Math.max(dp[left - 1][right] + nums[left - 1] * mul, dp[left][right - 1] + nums[n - right] * mul);
			}
		}
		int max = Integer.MIN_VALUE;
		for(int left = 0; left <= m; left++){
			max = Math.max(max, dp[left][m - left]);
		}
		return max;
    }
}
