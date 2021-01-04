class Solution392 {
    public boolean isSubsequence(String s, String t) {
         if(s.length() == 0){
           return true;
       }
    	int index = 0;
    	char cur = s.charAt(index);
    	for(int i = 0; i < t.length(); i++){
    		if(t.charAt(i) == cur){
    			index += 1;
    			if(index == s.length()){
    				return true;
    			}
    			cur = s.charAt(index);
    		}
    	}
    	return false;
    }

    public static void main(String[] args){
    	Solution392 s = new Solution392();
    	String test11 = "abc";
    	String test12 = "ahbgdc";
    	System.out.println(s.isSubsequence(test11, test12));
    	String test21 = "axc";
    	String test22 = "ahbgdc";
    	System.out.println(s.isSubsequence(test21, test22));
    }
}