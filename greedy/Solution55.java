class Solution55 {
    public boolean canJump(int[] nums) {
    	int cover = 0;
        int i = 0;
        while(i <= cover){
            cover = Math.max(cover, i + nums[i]);
            if(cover >= nums.length - 1){
                return true;
            }
            i += 1;
        }
        return false;
    }

    public static void main(String[] args){
    	Solution55 s = new Solution55();
    	int[] test1 = new int[]{3, 2, 1, 0, 4};
    	System.out.println(s.canJump(test1));
    }
}