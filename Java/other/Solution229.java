import java.util.Map;
import java.util.HashMap;
import java.util.List;
import java.util.LinkedList;
/**
class Solution229 {
    public List<Integer> majorityElement(int[] nums) {
    	List<Integer> result = new LinkedList<>();
    	Map<Integer, Integer> map = new HashMap<>();
    	for(int ele: nums){
    		if(map.containsKey(ele)){
    			map.put(ele, map.get(ele) + 1);
    		}
    		else{
    			map.put(ele, 1);
    		}
    	}
    	int number = nums.length / 3;
    	for(Integer ele: map.keySet()){
    		if(map.get(ele) > number){
    			result.add(ele);
    		}
    	}
    	return result;
    }
}
*/
class Solution229 {
    public List<Integer> majorityElement(int[] nums) {
        List<Integer> result = new LinkedList<>();
        int[] candidate1 = new int[2];
        int[] candidate2 = new int[2];
        for(int ele: nums){
            if(ele == candidate1[0]){
                candidate1[1] += 1;
            }
            else if(ele == candidate2[0]){
                candidate2[1] += 1;
            }
            else{
                if(candidate1[1] == 0){
                    candidate1[0] = ele;
                    candidate1[1] = 1;
                }
                else if(candidate2[1] == 0){
                    candidate2[0] = ele;
                    candidate2[1] = 1;
                }
                else{
                    candidate1[1] -= 1;
                    candidate2[1] -= 1;
                }
            }
        }
        int sum1 = 0, sum2 = 0;
        for(int ele: nums){
            if(ele == candidate1[0]){
                sum1 += 1;
            }
            if(ele == candidate2[0]){
                sum2 += 1;
            }
        }
        if(sum1 > nums.length / 3){
            result.add(candidate1[0]);
        }
        if(sum2 > nums.length / 3 && candidate2[0] != candidate1[0]){
            result.add(candidate2[0]);
        }
        return result;
    }
}