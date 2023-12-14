class Solution238 {
    public int[] productExceptSelf(int[] nums) {
    	int size = nums.length;
    	int[] result = new int[size];
    	int[] left = new int[size];
    	int[] right = new int[size];
    	left[0] = 1;
    	right[size - 1] = 1;
    	for(int i = 1; i < size; i++){
    		left[i] = left[i - 1] * nums[i - 1];
    	}
    	for(int i = size - 2; i >= 0; i--){
    		right[i] = right[i + 1] * nums[i + 1];
    	}
    	for(int i = 0; i < size; i++){
    		result[i] = left[i] * right[i];
    	}
    	return result;
    }

    public static void main(String[] args){
    	Solution238 s = new Solution238();
    	int[] test = {1, 2, 3, 4};
    	int[] result = s.productExceptSelf(test);
    }
}