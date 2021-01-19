import java.util.Stack;

class Solution85 {
    public int maximalRectangle(char[][] matrix) {
    	if(matrix.length == 0){
    		return 0;
    	}
    	int[][] heights = new int[matrix.length][matrix[0].length];
    	for(int i = 0; i < matrix.length; i++){
    		for(int j = 0; j < matrix[0].length; j++){
    			if(i == 0){
    				heights[i][j] = matrix[i][j] - '0';
    			}
    			else{
    				heights[i][j] = matrix[i][j] == '0' ? 0 : heights[i - 1][j] + 1;
    			}
    		}
    	}
    	int max = -1;
    	for(int i = 0; i < heights.length; i++){
    		Stack<Integer> stack = new Stack<>();
    		int[] left = new int[heights[0].length];
    		int[] right = new int[heights[0].length];
    		for(int j = 0; j < heights[0].length; j++){
    			while(!stack.empty() && heights[i][stack.peek()] >= heights[i][j]){
    				stack.pop();
    			}
    			left[j] = stack.empty() ? -1 : stack.peek();
    			stack.push(j);
    		}
    		stack.clear();
    		for(int j = heights[0].length - 1; j >= 0; j--){
    			while(!stack.empty() && heights[i][stack.peek()] >= heights[i][j]){
    				stack.pop();
    			}
    			right[j] = stack.empty() ? heights[0].length : stack.peek();
    			stack.push(j);
    		}
    		for(int k = 0; k < heights[0].length; k++){
    			int area = heights[i][k] * (right[k] - left[k] - 1);
    			max = Math.max(area, max);
    		}
    	}
    	return max;
    }
}