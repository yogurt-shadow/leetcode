class Solution5672 {
    public boolean check(int[] nums) {
    	int fall = 0;
    	for(int i = 0; i < nums.length; i++){
    		if(nums[(i + 1) % nums.length] < nums[i]){
    			fall += 1;
    			if(fall >= 2){
    				return false;
    			}
    		}
    	}
    	return true;
    }
}