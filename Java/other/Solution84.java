import java.util.Stack;

class Solution84 {
    public int largestRectangleArea(int[] heights) {
    	Stack<Integer> stack = new Stack<>();
    	int[] left = new int[heights.length];
    	int[] right = new int[heights.length];
    	for(int i = 0; i < heights.length; i++){
    		while(!stack.empty() && heights[stack.peek()] >= heights[i]){
    			stack.pop();
    		}
    		left[i] = stack.empty() ? -1 : stack.peek();
    		stack.push(i);
    	}

    	stack.clear();
    	for(int i = heights.length - 1; i >= 0; i--){
    		while(!stack.empty() && heights[stack.peek()] >= heights[i]){
    			stack.pop();
    		}
    		right[i] = stack.empty() ? heights.length : stack.peek();
    		stack.push(i);
    	}
    	int max = -1;
    	for(int ele = 0; ele < heights.length; ele++){
    		int area = heights[ele] * (right[ele] - left[ele] - 1);
    		max = Math.max(area, max);
    	}
    	return max;
    }
}