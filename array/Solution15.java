import java.util.Collections;
import java.util.List;
import java.util.LinkedList;
import java.util.Arrays;

class Solution15 {
	public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
		List<List<Integer>> result = new LinkedList<>();
        int point3 = nums.length - 1;

        loop1: for(int point1 = 0; point1 < nums.length; point1++){
            if(point1 > 0 && nums[point1] == nums[point1 - 1]){
                continue;
            }
          
            int target = -nums[point1];
            loop2: for(int point2 = point1 + 1; point2 < nums.length; point2++){
                if(point2 != point1 + 1 && nums[point2] == nums[point2 - 1]){
                    continue;
                }
                point3 = nums.length - 1;
                
             while(point3 > point2 && nums[point3] + nums[point2] > target){
                point3 -= 1;
             }
				if(point3 == point2){
					continue loop1;
				}
            if(nums[point2] + nums[point3] == target){
                    List<Integer> cur = new LinkedList<>();
                    cur.add(nums[point1]);
                    cur.add(nums[point2]);
                    cur.add(nums[point3]);
                    result.add(cur);

                    continue loop2;
                }

              }

            }
        return result;
	}

    public static void main(String[] args){
    	Solution15 s = new Solution15();
    	int[] test = new int[]{-1, 0, 1, 2, -1, -4, -2, -3, 3, 0, 4};
    	List<List<Integer>> list = s.threeSum(test);
	}
}
//[[-4,0,4],[-4,1,3],[-3,-1,4],[-3,0,3],[-3,1,2],[-2,-1,3],[-2,0,2],[-1,-1,2],[-1,0,1]]