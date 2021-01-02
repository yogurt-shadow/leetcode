class Solution394 {
    public String decodeString(String s) {
    	if(!s.contains("[")){
    		return s;
    	}
    	
        String result = "";
        int number = 0;
        for(int i = 0; i < s.length(); i++){
            char cur = s.charAt(i);
            if(cur >= 48 && cur <= 57){
                number = 10 * number + cur - 48;
            }

            if(cur >= 'a' && cur <= 'z'){
                result += cur;
            }

            if(cur == '['){
                int partner = find(s, i);
                String to_add = decodeString(s.substring(i + 1, partner));
                result = add(result, to_add, number);
                number = 0;
                i = partner;
            }

        }
        return result;
    }

    private String add(String s, String y, int number){
    	String b = s.substring(0, s.length());
        for(int i = 0; i < number; i++){
            b = b + y;
        }
        return b;
    }

    private int find(String s, int position){
        int level = 1;
        for(int i = position + 1; i < s.length(); i++){
            char cur = s.charAt(i);
            if(cur == '['){
                level += 1;
            }

            if(cur == ']'){
                level -= 1;
                if(level == 0){
                    return i;
                }
            }

        }
        return -1;
    }

    public static void main(String[] args){
    	String str1 = "abcsas";
    	Solution394 s = new Solution394();
    	System.out.println(s.decodeString(str1));
		String sss = "ada";
		String add = "123";
		System.out.println(s.add(sss, add, 3));

    	String test1 = "3[a]2[bc]";
    	System.out.println(s.decodeString(test1));

    	String test2 = "3[a2[c]]";
		System.out.println(s.decodeString(test2));

		String test3 = "2[abc]3[cd]ef";
		System.out.println(s.decodeString(test3));

		String test4 = "abc3[cd]xyz";
		System.out.println(s.decodeString(test4));
    }
}