class Solution1004 {
    public int longestOnes(int[] A, int K) {
    	int left = 0;
    	int right = 0;
    	int max = 0;
    	int count = 0;
    	while(right < A.length){
    		if(A[right] == 1){
    			count += 1;
    		}
    		int length = right - left + 1;
    		if(count + K < length){
    			left += 1;
    			if(A[left - 1] == 1){
    				count -= 1;
    			}
    		}
    		length = right - left + 1;
    		max = Math.max(length, max);
    		right += 1;
    	}
    	return max;
    }
}