class Solution67 {
    public String addBinary(String a, String b) {
    	String result = "";
    	int length = a.length();
    	if(a.length() > b.length()){
    		length = a.length();
    		while(b.length() != a.length()){
    			b = "0" + b;
    		}
    	}
    	if(a.length() < b.length()){
    		length = b.length();
    		while(b.length() != a.length()){
    			a = "0" + a;
    		}
    	}
    	boolean sum = false;
    	for(int i = length - 1; i >= 0; i--){
    		char aa = a.charAt(i);
    		char bb = b.charAt(i);
    		if(aa == '1' && bb == '1'){
    			result = sum ? "1" + result : "0" + result;
    			sum = true;
    		}

            else if(aa == '0' && bb == '0'){
                result = sum ? "1" + result : "0" + result;
                sum = false;
            }

            else{
                if(sum){
                    result = "0" + result;
                    sum = true;
                }
                else{
                    result = "1" + result;
                    sum = false;
                }
            }
    	}
        result = sum ? "1" + result : result;
        return result;
    }
}