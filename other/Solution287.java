class Solution287 {
    public int findDuplicate(int[] nums) {
    	int left = 1;
    	int right = nums.length - 1;
    	while(left != right){
    		int mid = (left + right) / 2;
    		int count = 0;
    		for(int ele: nums){
    			if(ele <= mid){
    				count += 1;
    			}
    		}
    		if(count <= mid){
    			left = mid + 1;
    		}
    		else{
    			right = mid;
    		}
    	}
    	return left;
    }

    public static void main(String[] args){
    	Solution287 s = new Solution287();
    	int[] test = {1, 3, 4, 2, 2};
    	System.out.println(s.findDuplicate(test));
    }
}