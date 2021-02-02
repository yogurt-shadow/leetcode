class Solution424 {
    public int characterReplacement(String s, int k) {
    	if(s.length() == 0){
    		return 0;
    	}
    	int[] freq = new int[26];
    	int left = 0;
    	int right = 0;
    	int max = 0;
    	char[] array = s.toCharArray();
    	while(right < s.length()){
    		int length = right - left + 1;
    		int cur = array[right] - 'A';
    		freq[cur] += 1;
    		max = Math.max(max, freq[cur]);
    		if(max + k < length){
    			freq[array[left] - 'A'] -= 1;
    			left += 1;
    		}
    		right += 1;
    	}
    	return right - left;
    }
}