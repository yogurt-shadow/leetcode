class Solution344 {
    public void reverseString(char[] s) {
    	int left = 0;
    	int right = s.length - 1;
    	while(right > left){
    		char cur = s[left];
    		s[left] = s[right];
    		s[right] = cur;
    		left += 1;
    		right -= 1;
    	}
    }
}