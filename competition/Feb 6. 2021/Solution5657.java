import java.util.*;

class Solution5657 {
    public int sumOfUnique(int[] nums) {
    	Map<Integer, Integer> map = new HashMap<>();
    	for(int ele: nums){
    		if(map.containsKey(ele)){
    			map.put(ele, map.get(ele) + 1);
    		}
    		else{
    			map.put(ele, 1);
    		}
    	}
    	int sum = 0;
    	for(Integer ele: map.keySet()){
    		if(map.get(ele) == 1){
    			sum += ele;
    		}
    	}
    	return sum;
    }
}