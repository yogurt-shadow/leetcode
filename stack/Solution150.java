import java.util.Stack;

class Solution150 {
    public int evalRPN(String[] tokens) {
    	Stack<Integer> stack = new Stack<>();
    	for(int i = 0; i < tokens.length; i++){
    		switch(tokens[i]){
    		case "+":
    		int b = stack.pop();
    		int a = stack.pop();
    		stack.push(a + b);
    		break;


    		case "-":
    		int b1 = stack.pop();
    		int a1 = stack.pop();
    		stack.push(a1 - b1);
    		break;


    		case "*":
    		int b2 = stack.pop();
    		int a2 = stack.pop();
    		stack.push(a2 * b2);
    		break;


    		case "/":
    		int b3 = stack.pop();
    		int a3 = stack.pop();
    		stack.push(a3 / b3);
    		break;


    		default:
    		stack.push(Integer.parseInt(tokens[i]));
    		break;
    	}
    	}

    	return stack.pop();
    }

    public static void main(String[] args){
    	String[] s1 = new String[]{"2", "1", "+", "3", "*"};
    	String[] s2 = new String[]{"4", "13", "5", "/", "+"};
    	String[] s3 = new String[]{"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};

    	Solution150 s = new Solution150();
    	System.out.println(s.evalRPN(s1));
    	System.out.println(s.evalRPN(s2));
    	System.out.println(s.evalRPN(s3));

    }
}