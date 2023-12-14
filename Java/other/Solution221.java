import java.util.Stack;

class Solution221 {
    public int maximalSquare(char[][] matrix) {
    	int m = matrix.length;
    	int n = matrix[0].length;
    	int[][] heights = new int[m][n];
    	for(int i = 0; i < m; i++){
    		for(int j = 0; j < n; j++){
    			if(i == 0){
    				heights[i][j] = matrix[i][j] - '0';
    			}
    			else{
    				heights[i][j] = matrix[i][j] == '0' ? 0 : heights[i - 1][j] + 1;
    			}
    		}
    	}
    	int max = 0;
    	int[] left = new int[n];
    	int[] right = new int[n];
    	for(int i = 0; i < m; i++){
    		Stack<Integer> stack1 = new Stack<>();
    		Stack<Integer> stack2 = new Stack<>();
    		for(int j = 0; j < n; j++){
    			while(!stack1.empty() && heights[i][j] <= heights[i][stack1.peek()]){
    				stack1.pop();
    			}
    			left[j] = stack1.empty() ? -1 : stack1.peek();
    			stack1.push(j);
    		}

    		for(int j = n - 1; j >= 0; j--){
    			while(!stack2.empty() && heights[i][j] <= heights[i][stack2.peek()]){
    				stack2.pop();
    			}
    			right[j] = stack2.empty() ? n : stack2.peek();
    			stack2.push(j);
    		}
    		for(int j = 0; j < n; j++){
    			int length = right[j] - left[j] - 1;
    			if(length >= heights[i][j]){
    				max = Math.max(max, heights[i][j] * heights[i][j]);
    			}
    		}
    	}
    	return max;
    }

    public static void  main(String[] args){
    	Solution221 s = new Solution221();
    	char[][] test = {{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
    	System.out.println(s.maximalSquare(test));
    }
}