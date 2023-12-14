class Solution1712 {
    public int waysToSplit(int[] nums) {
        int size = nums.length;
        int[] sum = new int[size + 1];
        for(int i = 1; i <= size; i++){
            sum[i] = sum[i - 1] + nums[i - 1];
        }
        long count = 0;
        int mod = 1000000000 + 7;
        int l = 2;
        int r = 2;
        for(int i = 1; i + 1 < size; i++){
            l = Math.max(l, i + 1);
            while(l < size && sum[l] - sum[i] < sum[i]){
                l += 1;
            }
            r = Math.max(r, l);
            while(r < size && sum[size] - sum[r] >= sum[r] - sum[i]){
                r += 1;
            }
            long cur = r - l;
            if(cur > 0){
                count += cur;
            }
        }
        return (int) (count % mod);
    }

    public static void main(String[] args){
    	Solution1712 s = new Solution1712();
    	int[] test = {1, 2, 2, 2, 5, 0};
    	System.out.println(s.waysToSplit(test));
    }
}