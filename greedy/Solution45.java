class Solution45 {
    public int jump(int[] nums) {
    	int step = 0;
    	int cover = 0;
    	int i = 0;
    	int lastcover = 0;
    	while(i <= cover && i < nums.length){
    		cover = Math.max(cover, i + nums[i]);
    		if(i == lastcover){
    			lastcover = cover;
    			if(i == nums.length - 1){
    				return step;
    			}
    			step += 1;
    		}
    		i += 1;
    	}
    	return step;
    }

    public static void main(String[] args){
    	Solution45 s = new Solution45();
    	int[] test1 = new int[]{2, 1};
    	System.out.println(s.jump(test1));
    }

}