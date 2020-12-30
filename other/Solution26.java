class Solution26 {
	public int removeDuplicates(int[] nums) {
		if(nums.length <= 1){
			return nums.length;
		}
		int i = 0;
		int j = 1;
		int length = 1;
		while(j < nums.length){
			if(nums[i] == nums[j]){
				j++;
			}
			else{
				length++;
				i++;
				nums[i] = nums[j];
			}

		}return length;
	}
}