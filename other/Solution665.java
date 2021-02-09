class Solution665 {
    public boolean checkPossibility(int[] nums) {
    	int fall = 0;
    	for(int i = 1; i < nums.length; i++){
    		if(nums[i - 1] > nums[i]){
    			fall += 1;
    			if(fall >= 2){
    				return false;
    			}
    			if (i > 1 && i < nums.length - 1 && nums[i - 1] > nums[i + 1] && nums[i - 2] > nums[i]) {
                return false;
            }
    	}
    }
    	return true;
  	}
}