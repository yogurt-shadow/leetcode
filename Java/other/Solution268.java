class Solution268 {
    public int missingNumber(int[] nums) {
    	int n = nums.length;
    	int sum1 = 0;
    	while(n != 0){
    		sum1 = sum1 ^ n;
    		n -= 1;
    	}
    	for(int ele: nums){
    		sum1 = sum1 ^ ele;
    	}
    	return sum1;
    }

    public static void main(String[] args){
    	Solution268 s = new Solution268();
    	System.out.println(3 ^ 10);
    	System.out.println(9 ^ 3);
    	System.out.println(9 ^ 10);
    }
}