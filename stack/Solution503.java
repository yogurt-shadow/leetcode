class Solution503 {
    public int[] nextGreaterElements(int[] nums) {
    	int length = nums.length;
    	int[] result = new int[length];
    	loop1: for(int i = 0; i < nums.length; i++){
    		int cur = nums[i];
    		for(int j = i + 1; index(j, length) != i; j++){
    			if(nums[index(j, length)] > cur){
    				result[i] = nums[index(j, length)];
    				continue loop1;
    			}
    		}
    		result[i] = -1;
    	}

    	return result;
    }

    private int index(int x, int length){
    	return x % length;
    }

    public static void main(String[] args){
    	Solution503 s = new Solution503();
    	int[] test = new int[]{1, 2, 3, 4, 3};
    	int[] output = s.nextGreaterElements(test);
    	for(int i = 0; i < output.length; i++){
    		System.out.println(output[i]);
    	}
    }
}