import java.util.Stack;

class Solution856 {
    public int scoreOfParentheses(String S) {
    	int value = 0;
    	for(int i = 0; i < S.length(); i++){
    		char cur = S.charAt(i);
    		if(cur == '('){
    			if(S.charAt(i + 1) == ')'){
    				value += 1;
    				i = i + 1;
    				continue;
    			}
    			int j = findanother(S, i);
    			String str = S.substring(i + 1, j + 1);
    			value += 2 * scoreOfParentheses(str);
    			i = j;
    			continue;
    		}
    	}
    	return value;
    }

    private int findanother(String S, int x){
    	int z = 1;
    	for(int i = x + 1; i < S.length(); i++){
    		char cur = S.charAt(i);
    		if(cur == '('){
    			z += 1;
    		}
    		if(cur == ')'){
    			z -= 1;
    			if(z == 0){
    				return i;
    			}
    		}
    	}
    	return -1;
    }

    public static void main(String[] args){
    	Solution856 s = new Solution856();
    	System.out.println(s.scoreOfParentheses("(()(()))"));
    }
}