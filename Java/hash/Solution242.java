class Solution242 {
    public boolean isAnagram(String s, String t) {
    	int[] freq = new int[26];
    	for(int i = 0; i < s.length(); i++){
    		char cur = s.charAt(i);
    		freq[cur - 'a'] += 1;
    	}

    	for(int j = 0; j < t.length(); j++){
    		char cur = t.charAt(j);
    		freq[cur - 'a'] -= 1;
    	}

    	for(int i = 0; i < 26; i++){
    		if(freq[i] != 0){
    			return false;
    		}
    	}
    	return true;
    }
}