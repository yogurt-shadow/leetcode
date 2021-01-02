import java.util.Stack;

class Solution456 {
    // problem 1 3 2
    public boolean find132pattern(int[] nums) {
    	Stack<Integer> stack = new Stack<>();
        int[] min = min(nums);
        for(int i = nums.length - 1; i > 0; i--){
            // make sure 3 > 1 (not 3 == 1)
            if(nums[i] > min[i]){ 
                // make sure stack elements are larger than min (2 > 1)
                while(!stack.empty() && stack.peek() <= min[i]){
                    stack.pop();
                }
                // check if 3 > 2
                if(!stack.empty() && nums[i] > stack.peek()){
                    return true;
                } 
                // store 3 as a choice of 2
                stack.push(nums[i]);
            }
           }
        return false;
    }

    private int[] min(int[] nums){
        int[] result = new int[nums.length];
        int cur_min = Integer.MAX_VALUE;
        for(int i = 0; i < nums.length; i++){
            if(nums[i] < cur_min){
                cur_min = nums[i];
            }
            result[i] = cur_min;
        }
        return result;
    }

    public static void main(String[] args){
    	Solution456 s = new Solution456();
    	int[] test1 = new int[]{1, 2, 3, 4};
    	System.out.println(s.find132pattern(test1));

    	int[] test2 = new int[]{3, 1, 4, 2};
    	System.out.println(s.find132pattern(test2));

        int[] test3 = new int[]{-1, 3, 2, 0};
        System.out.println(s.find132pattern(test3));


    }
}