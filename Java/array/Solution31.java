import java.util.Arrays;

class Solution31 {
    public void nextPermutation(int[] nums) {
    	if(nums.length < 2){
    		return;
    	}
    	for(int i = nums.length - 1; i > 0; i--){
    		if(nums[i - 1] < nums[i]){
    			for(int j = nums.length - 1; j >= i; j--) {
					if (nums[j] > nums[i - 1]) {
						int temp = nums[j];
						nums[j] = nums[i - 1];
						nums[i - 1] = temp;
						int point1 = i;
						int point2 = nums.length - 1;
						while (point2 > point1) {
							int cur = nums[point1];
							nums[point1] = nums[point2];
							nums[point2] = cur;
							point1 += 1;
							point2 -= 1;
						}
						return;
					}
				}
    		}
    	}
    	int point1 = 0, point2 = nums.length - 1;
    	while(point2 > point1){
    		int cur = nums[point1];
    		nums[point1] = nums[point2];
    		nums[point2] = cur;
    		point1 += 1;
    		point2 -= 1;
    	}
    }

    public static void main(String[] args){
    	Solution31 s = new Solution31();
    	int[] test1 = new int[]{2, 2, 0, 4, 3, 1};
    	s.nextPermutation(test1);
    	for(int i = 0; i < test1.length; i++){
    		System.out.println(test1[i]);
    	}
    }
}