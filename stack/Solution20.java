import java.util.Stack;

class Solution20 {
    public boolean isValid(String s) {
    	Stack<Integer> stack = new Stack<>();
    	for(int i = 0; i < s.length(); i++){
    		switch(s.charAt(i)){
    			case '(': 
    			stack.push(1);
    			break;

    			case '[':
    			stack.push(2);
    			break;

    			case '{':
    			stack.push(3);
    			break;

    			case ')':
    			if(stack.empty()){
    				return false;
    			}
    			if(stack.pop() != 1){
    				return false;
    			}
    			break;

    			case ']':
    			if(stack.empty()){
    				return false;
    			}
    			if(stack.pop() != 2){
    				return false;
    			}
    			break;

    			case '}':
    			if(stack.empty()){
    				return false;
    			}
    			if(stack.pop() != 3){
    				return false;
    			}
    			break;

    			default:
    			return false;
    		}
    	}
    	return stack.empty();
    }
}