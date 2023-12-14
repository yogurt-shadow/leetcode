class Solution674 {
    public int findLengthOfLCIS(int[] nums) {
    	if(nums.length == 0){
    		return 0;
    	}
    	int max = 1;
    	for(int i = 0; i < nums.length - max; i++){
    		int j = i;
    		while(j + 1 < nums.length && nums[j + 1] > nums[j]){
    			j += 1;
    		}
    		max = Math.max(max, j - i + 1);
    		i = j;
    	}
    	return max;
    }

    public static void main(String[] args){
    	Solution674 s = new Solution674();
    	int[] test1 = new int[]{1, 3, 5, 4, 7};
    	System.out.println(s.findLengthOfLCIS(test1));
    }
}