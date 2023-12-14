import java.util.Arrays;

class Solution16 {
    public int threeSumClosest(int[] nums, int target) {
    	Arrays.sort(nums);
    	int dist = Integer.MAX_VALUE;
    	int cur = 0;
    	for(int point1 = 0; point1 < nums.length; point1++){
    		if(point1 > 0 && nums[point1] == nums[point1 - 1]){
    			continue;
    		}
    		for(int point2 = point1 + 1; point2 < nums.length; point2++){
    			if(point2 != point1 + 1 && nums[point2] == nums[point2 - 1]){
    				continue;
    			}
    			int point3 = nums.length - 1;
    			while(point3 > point2){
    				if(Math.abs(nums[point1] + nums[point2] + nums[point3] - target) < dist){
    					cur = nums[point1] + nums[point2] + nums[point3];
    					dist = Math.abs(cur - target);
    				}
    				point3 -= 1;
    			}
    		}
    	}
    	return cur;
    }

    public static void main(String[] args){
    	Solution16 s = new Solution16();
    	int[] test1 = new int[]{-1, 2, 1, -4};
    	System.out.println(s.threeSumClosest(test1, 1));
    }
}