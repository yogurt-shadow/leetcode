class Solution13 {
    public int romanToInt(String s) {
    	int[] digit1 = new int[]{1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    	String[] digit2 = new String[]{"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    	int result = 0;
    loop:	for(int i = 0; i < s.length(); i++){
    		if(i + 1 < s.length()){
    			String cur = s.substring(i, i + 2);
    			for(int k = 0; k < digit1.length; k++){
    				if(cur.equals(digit2[k])){
    					result += digit1[k];
    					i = i + 1;
    					continue loop;
    				}
    			}
    		}
    		String cur = s.substring(i, i + 1);
    		for(int k = 0; k < digit1.length; k++){
    				if(cur.equals(digit2[k])){
    					result += digit1[k];
    					continue loop;
    				}
    			}
    	}
    	return result;
    }

    public static void main(String[] args){
    	Solution13 s = new Solution13();
    	System.out.println(s.romanToInt("MCMXCIV"));
	}
}