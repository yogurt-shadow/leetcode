class Solution14 {
    public String longestCommonPrefix(String[] strs) {
    	String result = "";
    	if(strs.length == 0){
    		return result;
    	}
    	for(int i = 0; i < strs[0].length(); i++){
    		char cur = strs[0].charAt(i);
    		for(String str: strs){
    			if(i >= str.length() || str.charAt(i) != cur){
    				return result;
    			}
    		}
    		result += cur;
    	}
    	return result;
    }
}