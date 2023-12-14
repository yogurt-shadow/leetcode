class Solution459 {
    public boolean repeatedSubstringPattern(String s) {
    	int length = s.length();
    	for(int length2 = 1; length2 <= length / 2; length2++){
    		if(length % length2  != 0){
    			continue;
    		}
    		String str = s.substring(0, length2);
    		if(match(str, s)){
    			return true;
    		}
    	}
    	return false;
    }

    private boolean match(String str, String s){
    	for(int start = 0; start < s.length(); start = start + str.length()){
    		if(!s.substring(start, start + str.length()).equals(str)){
    			return false;
    		}
    	}
    	return true;
    }
}