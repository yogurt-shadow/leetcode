class Solution215 {
    public int findKthLargest(int[] nums, int k) {
    	if(nums.length == 1){
    		return nums[0];
    	}

    	int pivot = nums[0];
    	int[] small = new int[nums.length - 1];
    	int[] big = new int[nums.length - 1];
    	int small_index = 0;
    	int big_index = 0;
    	for(int i = 1; i < nums.length; i++){
    		if(nums[i] >= pivot){
    			big[big_index] = nums[i];
    			big_index += 1;
    		}

    		else{
    			small[small_index] = nums[i];
    			small_index += 1;
    		}
    	}

    	if(k == big_index + 1){
    		return pivot;
    	}

    	if(k <= big_index){
    		int[] big2 = new int[big_index];
    		System.arraycopy(big, 0, big2, 0, big_index);
    		return findKthLargest(big2, k);
    	}

    	int[] small2 = new int[small_index];
    	System.arraycopy(small, 0, small2, 0, small_index);
    	return findKthLargest(small, k - big_index - 1);
    }
}