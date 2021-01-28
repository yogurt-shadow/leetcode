class Solution724 {
    public int pivotIndex(int[] nums) {
        if(nums.length <= 1){
            return nums.length - 1;
        }
        if(nums.length == 2){
            return -1;
        }
        int sum1 = 0;
        int sum2 = 0;
        for(int j = nums.length - 1; j >= 1; j--){
            sum2 += nums[j];
        }
        int i = 0;
        while(sum1 != sum2 && i < nums.length - 1){
            sum1 += nums[i];
            i += 1;
            sum2 -= nums[i];
        }
        return sum1 == sum2 ? i : -1;

    }

    public static void main(String[] args){
    	Solution724 s = new Solution724();
    	int[] nums1 = {0, 1, -1};
    	System.out.println(s.pivotIndex(nums1));
    }
}