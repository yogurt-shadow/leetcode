class Solution383 {
    public boolean canConstruct(String ransomNote, String magazine) {
    	int[] freq = new int[26];
    	for(int i = 0; i < magazine.length(); i++){
    		char cur = magazine.charAt(i);
    		freq[cur - 'a'] += 1;
    	}

    	for(int j = 0; j < ransomNote.length(); j++){
    		char cur = ransomNote.charAt(j);
    		freq[cur - 'a'] -= 1;
    	}

    	for(int x: freq){
    		if(x < 0){
    			return false;
    		}
    	}
    	return true;
    }
}