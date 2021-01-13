class Solution8 {
	public int myAtoi(String s) {
		String state = "start";
		int sign = 1;
		long number = 0;
		for(int i = 0; i < s.length(); i++){
			char cur = s.charAt(i);
			switch(state){
				case "start":
				if(cur == ' '){
					continue;
				}
				else if(cur == '+'){
					state = "signed";
				}
				else if(cur == '-'){
					state = "signed";
					sign = -1;
				}
				else if(cur >= '0' && cur <= '9'){
					state = "number";
					number = cur - '0';
				}
				else{
					return (int) number;
				}
				break;

				case "signed":
				if(cur >= '0' && cur <= '9'){
					state = "number";
					number = cur - '0';
				}
				else{
					return (int) number;
				}
				break;

				case "number":
				if(cur >= '0' && cur <= '9'){
					number = 10 * number + cur - '0';
					if(number > Integer.MAX_VALUE && sign == 1){
						return Integer.MAX_VALUE;
					}
					else if(sign == -1 && number + Integer.MIN_VALUE > 0){
					    return Integer.MIN_VALUE;
                    }
				}
				else{
					if(number > Integer.MAX_VALUE && sign == 1){
						return Integer.MAX_VALUE;
					}
					else if(sign == -1 && number + Integer.MIN_VALUE > 0){
					    return Integer.MIN_VALUE;
                    }
					else{
						return sign * (int) number;
					}
				}
				break;

				default:
				break;
			}
			}
        if(number > Integer.MAX_VALUE && sign == 1){
            return Integer.MAX_VALUE;
        }
        else if(sign == -1 && number + Integer.MIN_VALUE > 0){
            return Integer.MIN_VALUE;
        }
        else{
            return sign * (int) number;
        }

    }

    public static void main(String[] args){
    	Solution8 s = new Solution8();
    	System.out.println(s.myAtoi("9223372036854775808"));
    	System.out.println(s.myAtoi("  -42"));
    	System.out.println(s.myAtoi("4193 with words"));
    	System.out.println(s.myAtoi("words and 987"));
    	System.out.println(s.myAtoi("-91283472332"));

    }
  }