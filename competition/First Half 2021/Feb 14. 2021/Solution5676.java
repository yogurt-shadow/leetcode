class Solution5676 {
    public int minOperations(String s) {
    	StringBuilder str1 = new StringBuilder();
    	StringBuilder str2 = new StringBuilder();
    	for(int i = 0; i < s.length(); i++){
    		if(i % 2 == 0){
    			str1.append("0");
    			str2.append("1");
    		}
    		else{
    			str1.append("1");
    			str2.append("0");
    		}
    	}
    	return Math.min(diff(s, str1.toString()), diff(s, str2.toString()));
    }

    private int diff(String str1, String str2){
    	int result = 0;
    	for(int i = 0; i < str1.length(); i++){
    		if(str1.charAt(i) != str2.charAt(i)){
    			result += 1;
    		}
    	}
    	return result;
    }
}