import java.util.List;
import java.util.LinkedList;
import java.util.Arrays;

class Solution18 {
    public List<List<Integer>> fourSum(int[] nums, int target) {
    	Arrays.sort(nums);
    	List<List<Integer>> result = new LinkedList<>();
    	for(int point1 = 0; point1 < nums.length; point1++){
    		if(point1 > 0 && nums[point1] == nums[point1 - 1]){
    			continue;
    		}
    		for(int point2 = point1 + 1; point2 < nums.length; point2++){
    			if(point2 != point1 + 1 && nums[point2] == nums[point2 - 1]){
    				continue;
    			}

    			int tar = target -(nums[point1] + nums[point2]);
    			for(int point3 = point2 + 1; point3 < nums.length; point3++){
    				if(point3 != point2 + 1 && nums[point3] == nums[point3 - 1]){
    					continue;
    				}

    				int point4 = nums.length - 1;
    				while(point4 > point3 && nums[point3] + nums[point4] > tar){
    					point4 -= 1;
    				}
    				if(point3 == point4){
    					continue;
    				}

    				if(nums[point3] + nums[point4] == tar){
    					List<Integer> cur = new LinkedList<>();
    					cur.add(nums[point1]);
    					cur.add(nums[point2]);
    					cur.add(nums[point3]);
    					cur.add(nums[point4]);
    					result.add(cur);
    					continue;
    				}
    			}
    		}
    	}
    	return result;
    }

    public static void main(String[] args){
    	Solution18 s = new Solution18();
    	int[] test1 = new int[]{1, 0, -1, 0, -2, 2};
    	List<List<Integer>> result = s.fourSum(test1, 0);
    	
    }
}