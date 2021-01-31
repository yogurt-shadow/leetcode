class Solution1 {
    public String maximumTime(String time) {
    	char[] array = time.toCharArray();
    	if(array[0] == '?'){
    		if(array[1] != '?' && array[1] >= '4'){
    			array[0] = '1';
    		}
    		else{
    			array[0] = '2';
    		}
    	}
    	if(array[1] == '?'){
    		array[1] = array[0] == '2' ? '3' : '9';
    	}
    	if(array[3] == '?'){
    		array[3] = '5';
    	}
    	if(array[4] == '?'){
    		array[4] = '9';
    	}
    	return String.valueOf(array);
    }
}