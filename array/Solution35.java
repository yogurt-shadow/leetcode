class Solution35 {
    public int searchInsert(int[] nums, int target) {
    	for(int i = 0; i < nums.length; i++){
    		if(nums[i] >= target){
    			return i;
    		}
    	}
    	return nums.length;
    }

    public static  void main(String[] args){
    	Solution35 s = new Solution35();
    	int[] test1 = new int[]{1, 3, 5, 6};
    	System.out.println(s.searchInsert(test1, 5));
	}
}