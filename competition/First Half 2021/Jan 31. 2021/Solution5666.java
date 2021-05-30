class Solution5666 {
    public boolean checkPartitioning(String s) {
    	boolean[][] dp = new boolean[s.length()][s.length()];
    	for(int i = 0; i < s.length(); i++){
    		dp[i][i] = true;
    		if(i + 1 < s.length()){
    			dp[i][i + 1] = s.charAt(i) == s.charAt(i + 1);
    		}
    	}
    	for(int center = 1; center < s.length() - 1; center++){
            for(int value = 1; center - value >= 0 && center + value < s.length(); value++){
                int left = center - value;
                int right = center + value;
                dp[left][right] = s.charAt(left) == s.charAt(right) && dp[left + 1][right - 1];
            }
        }

        for(int left = 1; left + 2 < s.length(); left++){
            int right = left + 1;
            for(int value = 1; left - value >= 0 && right + value < s.length(); value++){
                int left2 = left - value;
                int right2 = right + value;
                dp[left2][right2] = s.charAt(left2) == s.charAt(right2) && dp[left2 + 1][right2 - 1];
            }
        }

    	for(int left = 1; left < s.length() - 1; left++){
    		for(int right = left; right < s.length() - 1; right++){
    			if(dp[0][left - 1] && dp[left][right] && dp[right + 1][s.length() - 1]){
    				return true;
    			}
    		}
    	}
    	return false;
    }

    public static void main(String[] args){
    	Solution5666 s = new Solution5666();
    	String str = "tnzogabxzbxjvvjxbzxbagoznwxongqgmywvinnnivwymgqgnoxw";
    	System.out.println(s.checkPartitioning(str));
	}
}