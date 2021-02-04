class Solution153 {
    public int findMin(int[] nums) {
    	if(nums.length == 1){
    		return nums[0];
    	}
    	if(nums.length == 2){
    		return Math.min(nums[0], nums[1]);
    	}
    	int left = nums[0];
    	int right = nums[nums.length - 1];
    	int middle = nums[nums.length / 2];
        if(left < right){
            return left;
        }
    	if(middle < nums[nums.length / 2 - 1] && middle < nums[nums.length / 2 + 1]){
    		return middle;
    	}
    	if(middle < right){
    		int[] copy = new int[nums.length / 2 + 1];
    		System.arraycopy(nums, 0, copy, 0, nums.length / 2 + 1);
    		return findMin(copy);
    	}
    	else{
    		int[] copy = new int[nums.length - nums.length / 2];
    		System.arraycopy(nums, nums.length / 2, copy, 0, copy.length);
    		return findMin(copy);
    	}
    }

    public static void main(String[] args){
        Solution153 s = new Solution153();
        int[] test = {4,5,6,7,0,1,2};
        System.out.println(s.findMin(test));
    }
}