import java.util.*;

class Solution5692 {
	private int[][] copy;

    public double[] getCollisionTimes(int[][] cars) {
    	copy = cars;
    	int size = cars.length;
    	double[] res = new double[size];
    	Stack<Integer> stack = new Stack<>();
    	for(int i = size - 1; i >= 0; i--){
    		while(!stack.empty() && res[stack.peek()] > 0 && (cars[i][1] <= cars[stack.peek()][1] || calTime(i, stack.peek()) > res[stack.peek()])){
    			stack.pop();
    		}
    		if(stack.empty() || cars[i][1] <= cars[stack.peek()][1]){
    			res[i] = -1;
    		}
    		else{
    			res[i] = calTime(i, stack.peek());
    		}
    		stack.push(i);
    	}
    	return res;
    }

	private double calTime(int index1, int index2){
		return (double) (copy[index2][0] - copy[index1][0]) / (double) (copy[index1][1] - copy[index2][1]);
	}
}