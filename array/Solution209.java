class Solution209 {
    public int minSubArrayLen(int s, int[] nums) {
        boolean changed = false;
    	int left = 0;
    	int result = Integer.MAX_VALUE;
    	int sum = 0;
    	for(int right = 0; right < nums.length; right++){
    		sum += nums[right];
    		while(sum >= s){
    			
    			int length = right - left + 1;
    			if(length < result){
                    changed = true;
    				result = length;
    			}
    			left += 1;
    			sum -= nums[left - 1];
    		}
    	}
    	if(changed){
            return result;
        }
        else{
            return 0;
        }
    }

    public static void main(String[] args){
    	Solution209 s = new Solution209();
    	int[] test1 = new int[]{2, 3, 1, 2, 4, 3};
    	System.out.println(s.minSubArrayLen(7, test1));
    }
}