class Solution151 {
    public String reverseWords(String s) {
    	String str = "";
    	StringBuilder result = new StringBuilder();
    	for(int i = s.length() - 1; i >= 0; i--){
    		char cur = s.charAt(i);
    		if(cur == ' '){
    			if(str.length() > 0){
    				result.append(str);
    				result.append(" ");
    				str = "";
    			}
    		}
    		else{
    			str = cur + str;
    			if(i == 0){
    				result.append(str);
    				result.append(" ");
    			}
    		}
    	}
    	String re = result.toString();
    	return re.substring(0, re.length() - 1);
    }

    public static void main(String[] args){
    	Solution151 s = new Solution151();
    	System.out.println(s.reverseWords("the sky is blue"));
	}
}