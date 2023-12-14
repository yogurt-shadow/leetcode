class Solution41 {
    public int firstMissingPositive(int[] nums) {
    	boolean[] showup = new boolean[nums.length + 1];
    	for(int ele: nums){
    		if(ele >= 1 && ele <= nums.length){
    			showup[ele] = true;
    		}
    	}
    	for(int i = 1; i < showup.length; i++){
    		if(!showup[i]){
    			return i;
    		}
    	}
    	return showup.length;
    }
}