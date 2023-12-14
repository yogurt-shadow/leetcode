import java.util.Stack;

class Solution735 {
    public int[] asteroidCollision(int[] asteroids) {
    	Stack<Integer> stack = new Stack<>();
    	for(int i = 0; i < asteroids.length; i++){
            stack.push(asteroids[i]);
    		verify(stack);
    	}

    	int[] result = new int[asteroids.length];
    	int index = result.length - 1;
    	while(!stack.empty()){
    		result[index] = stack.pop();
    		index -= 1;
    	}

    	int[] output = new int[result.length - 1  - index];
    	System.arraycopy(result, index + 1, output, 0, result.length - 1 - index);
    	return output;
    }

    private void verify(Stack<Integer> stack){
        if(stack.empty()){
            return;
        }
        int x = stack.pop();
        if(stack.empty() || x * stack.peek() > 0 || (stack.peek() < 0 && x > 0)){
            stack.push(x);
            return;
        }

        if(-x > stack.peek()){
            stack.pop();
            stack.push(x);
            verify(stack);
        }

        else if(-x == stack.peek()){
            stack.pop();
            verify(stack);
        }

        else if(-x < stack.peek()){
            verify(stack);
        }
    }

    public static void main(String[] args){
    	Solution735 s = new Solution735();
    	int[] test1 = new int[]{5, 10, -5};
    	int[] test2 = new int[]{8, -8};
    	int[] test3 = new int[]{10, 2, -5};
    	int[] test4 = new int[]{-2, -1, 1, 2};

    	int[] output1 = s.asteroidCollision(test1);
    	int[] output2 = s.asteroidCollision(test2);
    	int[] output3 = s.asteroidCollision(test3);
		int[] output4 = s.asteroidCollision(test4);

		for(int i = 0; i < output1.length; i++){
			System.out.print(output1[i] + " ");
		}
		System.out.println();

		for(int i = 0; i < output2.length; i++){
			System.out.print(output2[i] + " ");
		}
		System.out.println();

		for(int i = 0; i < output3.length; i++){
			System.out.print(output3[i] + " ");
		}
		System.out.println();

		for(int i = 0; i < output4.length; i++){
			System.out.print(output4[i] + " ");
		}
		System.out.println();


    }
}