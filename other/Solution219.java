import java.util.Map;
import java.util.HashMap;
import java.util.List;
import java.util.LinkedList;

class Solution219 {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
    	Map<Integer, List<Integer>> map = new HashMap<>();
    	for(int i = 0; i < nums.length; i++){
    		if(map.containsKey(nums[i])){
    			List<Integer> list = map.get(nums[i]);
    			if(i - list.get(list.size() - 1) <= k){
    				return true;
    			}
    			map.get(nums[i]).add(i);
    		}
    		else{
    			map.put(nums[i], new LinkedList<>());
    			map.get(nums[i]).add(i);
    		}
    	}
    	return false;
    }
}