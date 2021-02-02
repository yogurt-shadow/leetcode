class Solution395 {
    public int longestSubstring(String s, int k) {
    	int max = 0;
    	char[] array = s.toCharArray();
    	for(int i = 0; i < s.length(); i++){
    		int[] freq = new int[26];
    		for(int j = i; j < s.length(); j++){
    			freq[array[j] - 'a'] += 1;
    			if(match(freq, k)){
    				max = Math.max(max, j - i + 1);
    			}
    		}
    	}
    	return max;
    }

    private boolean match(int[] freq, int k){
    	for(int ele: freq){
    		if(ele > 0 && ele < k){
    			return false;
    		}
    	}
    	return true;
    }
}