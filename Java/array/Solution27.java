class Solution27 {
    public int removeElement(int[] nums, int val) {
    	int i = 0, j = 0;
    	while(j < nums.length){
    		if(nums[j] == val){
    			j += 1;
    		}
    		else{
    			nums[i] = nums[j];
    			i += 1;
    			j += 1;
    		}
    	}
    	return i;
    }

    public static void main(String[] args){
    	Solution27 s = new Solution27();
    	int[] test1 = new int[]{3, 2, 2, 3};
    	System.out.println(s.removeElement(test1, 2));
    	for(int i = 0; i < 2; i++){
    		System.out.println(test1[i]);
    	}
    }
}