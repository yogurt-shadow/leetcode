class Solution38 {
    public String countAndSay(int n) {
    	if(n == 1){
    		return "1";
    	}
    	return describe(countAndSay(n - 1));
    }

    private String describe(String s){
    	String result = "";
    	int count = 0;
    	char number = ' ';
    	for(int i = 0; i < s.length(); i++){
    		char cur = s.charAt(i);
    		if(count == 0){
    			number = cur;
    			count = 1;
    		}

    		else if(cur != number){
    			result += String.valueOf(count);
    			result += number;
    			number = cur;
    			count = 1;
    		}

    		else{
    			count += 1;
			}

    		if(i == s.length() - 1){
    			result += String.valueOf(count);
    			result += number;
    		}
    	}
    	return result;
    }

    public static void main(String[] args){
    	Solution38 s = new Solution38();
    	System.out.println(s.describe("111"));
    	System.out.println(s.describe("2112"));
    }
}