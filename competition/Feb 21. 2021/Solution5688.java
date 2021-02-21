class Solution5688 {
    public int longestPalindrome(String word1, String word2) {
    	int size1 = word1.length(), size2 = word2.length();
    	String word = word1 + word2;
    	int size = size1 + size2;
    	int ans = word.charAt(size1 - 1) == word.charAt(size1) ? 2 : 0;
    	int[][] dp = new int[size][size];
    	for(int i = 0; i < size; i++){
    		dp[i][i] = 1;
    		if(i + 1 < size){
    			dp[i][i + 1] = word.charAt(i) == word.charAt(i + 1) ? 2 : 1;
    		}
    	}
    	for(int length = 3; length <= size; length++){
    		for(int left = 0; left + length - 1 < size; left++){
    			int right = left + length - 1;
    			if(word.charAt(left) == word.charAt(right)){
    				dp[left][right] = dp[left + 1][right - 1] + 2;
    				if(left < size1 && right >= size1){
    					ans = Math.max(ans, dp[left][right]);
    				}
    			}
    			else{
    				dp[left][right] = Math.max(dp[left + 1][right], dp[left][right - 1]);
    			}
    		}
    	}
    	return ans;
    }

    public static void main(String[] args){
    	Solution5688 s = new Solution5688();
    	String word1 = "aaa", word2 = "aa";
    	System.out.println(s.longestPalindrome(word1, word2));
    }
}