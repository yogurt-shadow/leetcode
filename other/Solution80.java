class Solution80 {
    public int removeDuplicates(int[] nums) {
    	if(nums.length <= 2){
    		return nums.length;
    	}
    	int left = 1;
    	int right = 2;
    	for(; right < nums.length; right++){
    		if(nums[left - 1] != nums[right]){
    			left += 1;
    			nums[left] = nums[right];
    		}
    	}
    	return left + 1;
    }

    public static void main(String[] args){
    	Solution80 s = new Solution80();
    	int[] nums = {0,0,1,1,1,1,2,3,3};
    	s.removeDuplicates(nums);
    }
}