class Solution55 {
    public boolean canJump(int[] nums) {
    	if(nums.length == 1){
    		return true;
    	}
    	loop1: for(int i = nums.length - 2; i >= 0; i--){
    		if(nums[i] == 0){
    			for(int j = i - 1; j >= 0; j--){
    				if(j + nums[j] > i){
    					continue loop1;
    				}
    			}
    			return false;
    		}
    	}
    	return true;
    }

    public static void main(String[] args){
    	Solution55 s = new Solution55();
    	int[] test1 = new int[]{3, 2, 1, 0, 4};
    	System.out.println(s.canJump(test1));
    }
}