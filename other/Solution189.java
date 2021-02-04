class Solution189 {
    public void rotate(int[] nums, int k) {
    	int[] copy = new int[nums.length];
    	System.arraycopy(nums, 0, copy,0, nums.length);
    	for(int i = 0; i < nums.length; i++){
    		nums[(i + k) % nums.length] = copy[i];
    	}
    }
}