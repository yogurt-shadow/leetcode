class Solution541 {
    public String reverseStr(String s, int k) {
    	char[] ele = s.toCharArray();
    	for(int i = 0; i < s.length(); i += 2 * k){
    		int left = i; 
    		int right = i + k - 1;
    		if(i + k - 1 >= s.length()){
    			right = s.length() - 1;
    		}
    		while(right > left){
    			char cur = ele[left];
    			ele[left] = ele[right];
    			ele[right] = cur;
    			left += 1;
    			right -= 1;
    		}
    	}
    	return String.valueOf(ele);
    }

    public static void main(String[] args){
    	Solution541 s = new Solution541();
    	System.out.println(s.reverseStr("abcdefg", 2));
    	System.out.println(s.reverseStr("abcdefg", 10));

    }
}