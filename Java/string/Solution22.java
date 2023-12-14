import java.util.List;
import java.util.LinkedList;

class Solution22 {
    public List<String> generateParenthesis(int n) {
    	List<String> result = new LinkedList<>();
    	put(result, "", 1, 2 * n);
    	return result;
    }

    private void put(List<String> result, String str, int cur, int end){
    	char[] choice = new char[]{'(', ')'};
    	for(int i = 0; i < 2; i++){
    		String str2 = str + choice[i];
    		if(cur == end && is_valid(str2)){
    			result.add(str2);
    		    return;
    		}

    		if(cur == end && !is_valid(str2)){
    			continue;
			}
    		put(result, str2, cur + 1, end);
    	}
    }

    private boolean is_valid(String s){
    	int k = 0;
    	for(int i = 0; i < s.length(); i++){
    		char cur = s.charAt(i);
    		if(cur == '('){
    			k += 1;
    		}
    		if(cur == ')'){
    			k -= 1;
    			if(k < 0){
    				return false;
    			}
    		}
    	}
    	return k == 0;
    }

    public static void main(String[] args){
        Solution22 s = new Solution22();
        List<String> result = s.generateParenthesis(3);
    }
}