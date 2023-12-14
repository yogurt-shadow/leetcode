class Solution28 {
    public int strStr(String haystack, String needle) {
    	if(needle.length() == 0){
    		return 0;
    	}
    	int length = needle.length();
    	for(int i = 0; i + length - 1< haystack.length(); i++){
    		if(haystack.substring(i, i + length).equals(needle)){
    			return i;
    		}
    	}
    	return -1;
    }
}