class Solution283 {
    public void moveZeroes(int[] nums) {
    	int count = 0;
    	int index = 0;
    	while(index + count < nums.length){
    		if(nums[index] != 0){
    			index += 1;
    		}
    		else{
    			while(index + count < nums.length && nums[index + count] == 0){
    				count += 1;
    			}
    			int last = index + count - 1;
    			if(last + 1 < nums.length){
    				int cur = nums[last + 1];
    				nums[index] = cur;
    				nums[last + 1] = 0;
    			}
    			index += 1;
    		}
    	}
    }

    public static void main(String[] args){
    	Solution283 s = new Solution283();
    	int[] test = {0, 1, 0, 3, 2};
    	s.moveZeroes(test);
    }
}