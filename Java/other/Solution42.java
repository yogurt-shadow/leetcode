import java.util.Stack;

class Solution42 {
    public int trap(int[] height) {
    	int sum = 0;
    	Stack<int[]> stack = new Stack<>();
    	for(int i = 0; i < height.length; i++){
    		if(stack.empty() || stack.peek()[0] > height[i]){
    			stack.push(new int[]{height[i], i});
    			continue;
    		}
    		int last = stack.pop()[0];
    		while(!stack.empty() && stack.peek()[0] <= height[i]){
    			int[] peek = stack.peek();
    			int distance = i - peek[1] - 1;
    			sum += (Math.min(peek[0], height[i]) - last) * distance;
    			last = stack.pop()[0];
    		}
    		if(!stack.empty()){
    			int distance = i - stack.peek()[1] - 1;
    			sum += (Math.min(height[i], stack.peek()[0]) - last) * distance;
			}
    		stack.push(new int[]{height[i], i});
    	}
    	return sum;
    }

    public static void main(String[] args){
        Solution42 s = new Solution42();
        int[] height = {4,2,0,3,2,5};
        System.out.println(s.trap(height));
    }
}