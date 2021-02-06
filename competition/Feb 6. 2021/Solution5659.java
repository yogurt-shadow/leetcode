class Solution5659 {
    public int minimumLength(String s) {
    	if(s.length() == 1){
    		return 1;
		}
    	int left = 0;
    	int right = s.length() - 1;
    	char cur = s.charAt(left);
    	if(s.charAt(right) != cur){
    		return s.length();
    	}
    	while(left + 1< s.length() && s.charAt(left + 1) == cur){
    		left += 1;
    	}
    	while(right - 1 >= 0 && s.charAt(right - 1) == cur){
    		right -= 1;
    	}
    	if(left == s.length() - 1){
    		return 0;
    	}
    	return minimumLength(s.substring(left + 1, right));
    }

    public static void main(String[] args){
    	Solution5659 s = new Solution5659();
    	System.out.println(s.minimumLength("aa"));
    }
}