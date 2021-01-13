class Solution58 {
    public int lengthOfLastWord(String s) {
    	int x = 0;
        boolean collected = false;
    	for(int i = s.length() - 1; i >= 0; i--){
    		char cur = s.charAt(i);
    		if(cur != ' '){
    			x += 1;
    			collected = true;
    		}
    		else if(collected){
                return x;
            }
    	}
    	return x;
    }

    public static void main(String[] args){
    	Solution58 s = new Solution58();
    	System.out.println(s.lengthOfLastWord("a "));
    }
}