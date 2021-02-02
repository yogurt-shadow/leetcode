class Solution567 {
    public boolean checkInclusion(String s1, String s2) {
        if(s2.length() < s1.length()){
            return false;
        }
    	int[] freq1 = new int[26];
    	int[] freq2 = new int[26];
    	for(int i = 0; i < s1.length(); i++){
    		char cur = s1.charAt(i);
    		freq1[cur - 'a'] += 1;
    	}
    	int left = 0;
    	int right = left + s1.length() - 1;
    	for(int i = left; i <= right; i++){
    		char cur = s2.charAt(i);
    		freq2[cur - 'a'] += 1;
    	}
    	while(right < s2.length()){
    		if(equal(freq1, freq2)){
    			return true;
    		}
    		right += 1;
    		if(right < s2.length()){
    		freq2[s2.charAt(right) - 'a'] += 1;
    	}
    	freq2[s2.charAt(left) - 'a'] -= 1;
    	left += 1;
    	}
    	return false;
    }

    private boolean equal(int[] a, int[] b){
    	for(int i = 0; i < a.length; i++){
    		if(a[i] != b[i]){
    			return false;
    		}
    	}
    	return true;
    }
}