/**  jianzhi offer */
class Solution5 {
    public String replaceSpace(String s) {
    	char[] ele = new char[s.length() * 3];
    	int index = 0;
    	for(int i = 0; i < s.length(); i++){
    		char cur = s.charAt(i);
    		if(cur == ' '){
    			ele[index] = '%';
    			ele[index + 1] = '2';
    			ele[index + 2] = '0';
    			index = index + 3;
    		}
    		else{
    			ele[index] = cur;
    			index += 1;
    		}
    	}
    	char[] ele2 = new char[index];
    	System.arraycopy(ele, 0, ele2, 0, index);
    	return String.valueOf(ele2);
    }
}