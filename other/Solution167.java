class Solution167 {
    public int[] twoSum(int[] numbers, int target) {
    	int left = 0;
    	int right = numbers.length - 1;
    	while(left < right){
    		int cur = numbers[left] + numbers[right];
    		if(cur == target){
    			return new int[]{left + 1, right + 1};
    		}
    		if(cur > target){
    			right -= 1;
    		}
    		else{
    			left += 1;
    		}
    	}
    	return new int[0];
    }
}