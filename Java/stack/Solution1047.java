import java.util.Stack;

class Solution1047 {
	/**
	*  Recursion
    public String removeDuplicates(String S) {
    	while(havedulicates(S)){
    		S = removeDuplicates2(S);
    	}
    	return S;
    }

    private boolean havedulicates(String S){
    	for(int i = 0; i + 1 < S.length(); i++){
    		if(S.charAt(i) == S.charAt(i + 1)){
    			return true;
    		}
    	}
    	return false;
    }

    private String removeDuplicates2(String S){
    	StringBuilder str = new StringBuilder();
    	for(int i = 0; i < S.length(); i++){
    		if(i + 1 < S.length() && S.charAt(i) == S.charAt(i + 1)){
    			i = i + 1;
    		}
    		else{
    			str.append(S.charAt(i));
    		}
    	}
    	return str.toString();
    }
    */

    public String removeDuplicates(String S) {
    	Stack<Character> stack = new Stack<>();
    	for(int i = 0; i < S.length(); i++){
    		char cur = S.charAt(i);
    		if(!stack.empty() && stack.peek() == cur){
    			stack.pop();
    		}
    		else{
    			stack.push(cur);
    		}
    	}
    	StringBuilder str = new StringBuilder();
    	while(!stack.empty()){
    		str.insert(0, stack.pop());
    	}
    	return str.toString();
    }

    public static void main(String[] args){
    	Solution1047 s = new Solution1047();
    	System.out.println(s.removeDuplicates("abbaca"));
    }
}