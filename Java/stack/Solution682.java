import java.util.Stack;

class Solution682 {
    public int calPoints(String[] ops) {
    	Stack<Integer> stack = new Stack<>();
    	for(int i = 0; i < ops.length; i++){
    		String cur = ops[i];
    		if(cur.equals("D")){
    			stack.push(stack.peek() * 2);
    		}

    		else if(cur.equals("C")){
    			stack.pop();
    		}

    		else if(cur.equals("+")){
    			int b = stack.pop();
    			int a = stack.pop();
    			stack.push(a);
    			stack.push(b);
    			stack.push(a + b);
    		}
    		else{
    			stack.push(Integer.parseInt(cur));
    		}

    	}

    	int sum = 0;
    	while(!stack.empty()){
    		sum += stack.pop();
    	}
    	return sum;
    }

    public static void main(String[] args){
    	Solution682 s = new Solution682();
    	String[] test1 = new String[]{"5","2","C","D","+"};
    	String[] test2 = new String[]{"5","-2","4","C","D","9","+","+"};
    	String[] test3 = new String[]{"1"};

    	System.out.println(s.calPoints(test1));
    	System.out.println(s.calPoints(test2));
    	System.out.println(s.calPoints(test3));
    }
}