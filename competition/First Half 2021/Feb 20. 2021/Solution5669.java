class Solution5669 {
    public boolean canChoose(int[][] groups, int[] nums) {
    	int size = groups.length;
    	if(size == 0){
    		return true;
    	}
    	int start = groups[0].length;
    loop:	for(int i = 0; i + start - 1 < nums.length; i++){
    		for(int j = i; j <= i + start - 1; j++) {
				if (nums[j] != groups[0][j - i]) {
					continue loop;
				}
			}
    			int[][] group2 = new int[groups.length - 1][];
    			System.arraycopy(groups, 1, group2, 0, group2.length);
    			int[] nums2 = new int[nums.length - (i + start)];
    			System.arraycopy(nums, i + start, nums2, 0, nums2.length);
    			return canChoose(group2, nums2);
    		}
    	return false;
    }

    public static void main(String[] args){
    	Solution5669 s = new Solution5669();
    	int[][] groups = {{352529,-4284030,6431387,2432677,-3305342,-4342915,-9007629,3195451,-9587228,5747770,8106556,-2385247,3207013,-8540809,9400364,6852329},{9903943}};
		int[] nums = {-8540809,5747770,2432677,-9587228,3195451,352529,-4284030,6431387,2432677,-3305342,-4342915,-9007629,3195451,-9587228,5747770,8106556,-2385247,3207013,-8540809,-8540809,6852329,-9007629,352529,9903943};
		System.out.println(s.canChoose(groups, nums));
	}
}