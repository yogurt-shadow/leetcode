class Solution12 {
    public String intToRoman(int num) {
    	int[] digit1 = new int[]{1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    	String[] digit2 = new String[]{"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    	String result = "";
   loop: while(num > 0){
    		for(int i = 0; i < digit1.length; i++){
    			if(i == digit1.length - 1 || ( num >= digit1[i] && num < digit1[i + 1])){
    				result += digit2[i];
    				num = num - digit1[i];
    				continue loop;
    			}
    		}
    	}
    	return result;
    }

    public static void main(String[] args){
    	Solution12 s = new Solution12();
    	System.out.println(s.intToRoman(9));
        System.out.println(s.intToRoman(58));
        System.out.println(s.intToRoman(20));
        System.out.println(s.intToRoman(1994));
    }
}