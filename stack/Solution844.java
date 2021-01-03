import java.util.Stack;

class Solution844 {
    public boolean backspaceCompare(String S, String T) {
        Stack<Character> stack1 = new Stack<>();
        Stack<Character> stack2 = new Stack<>();
        for(int i = 0; i < S.length(); i++){
        	char cur = S.charAt(i);
        	if(cur == '#'){
        		if(!stack1.empty()){
        			stack1.pop();
        		}
        	}

        	else{
        		stack1.push(cur);
        	}
        }

        for(int i = 0; i < T.length(); i++){
        	char cur = T.charAt(i);
        	if(cur == '#'){
        		if(!stack2.empty()){
        			stack2.pop();
        		}
        	}

        	else{
        		stack2.push(cur);
        	}
        }

        while(!stack1.empty() && !stack2.empty()){
        	if(stack1.pop() != stack2.pop()){
        		return false;
        	}
        }

        return stack1.empty() && stack2.empty();
    }
}