class Solution75 {
    public void sortColors(int[] nums) {
    	int[] freq = new int[3];
    	for(int ele: nums){
    		freq[ele] += 1;
    	}
    	for(int i = 0; i < freq[0]; i++){
    		nums[i] = 0;
    	}
    	for(int i = freq[0]; i < freq[0] + freq[1]; i++){
    		nums[i] = 1;
    	}
    	for(int i = freq[0] + freq[1]; i < nums.length; i++){
    		nums[i] = 2;
    	}
    }
}