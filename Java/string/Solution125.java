class Solution125 {
    public boolean isPalindrome(String s) {
    	StringBuilder str = new StringBuilder();
    	for(int i = 0; i < s.length(); i++){
    		char cur = s.charAt(i);
    		if(cur >= '0' && cur <= '9'){
    			str.append(cur);
    		}
    		if(cur >= 'a' && cur <= 'z'){
    			str.append(cur);
    		}
    		if(cur >= 'A' && cur <= 'Z'){
    			char convert = (char) (cur - 'A' + 'a');
    			str.append(convert);
    		}
    	}
    	return isPalindrome2(str.toString());
    }

    private boolean isPalindrome2(String str){
    	int left = 0;
    	int right = str.length() - 1;
    	while(right >= left){
    		char left_c = str.charAt(left);
    		char right_c = str.charAt(right);
    		if(left_c != right_c){
    			return false;
    		}
    		left += 1;
    		right -= 1;
    	}
    	return true;
    }

    public static void main(String[] args){
    	Solution125 s = new Solution125();
    	System.out.println(s.isPalindrome("A man, a plan, a canal: Panama"));
    }
}