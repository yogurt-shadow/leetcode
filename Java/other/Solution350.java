import java.util.Map;
import java.util.HashMap;

class Solution350 {
    public int[] intersect(int[] nums1, int[] nums2) {
    	Map<Integer, Integer> map1 = new HashMap<>();
    	Map<Integer, Integer> map2 = new HashMap<>();
    	for(int ele: nums1){
    		if(!map1.containsKey(ele)){
    			map1.put(ele, 1);
    		}
    		else{
    			map1.put(ele, map1.get(ele) + 1);
    		}
    	}
    	for(int ele: nums2){
    		if(!map2.containsKey(ele)){
    			map2.put(ele, 1);
    		}
    		else{
    			map2.put(ele, map2.get(ele) + 1);
    		}
    	}
    	Map<Integer, Integer> map = new HashMap<>();
    	int size = 0;
    	for(Integer ele: map1.keySet()){
    		if(map2.containsKey(ele)){
    			int freq = Math.min(map1.get(ele), map2.get(ele));
    			map.put(ele, freq);
    			size += freq;
    		}
    	}
    	int[] result = new int[size];
    	int index = 0;
    	for(Integer ele: map.keySet()){
    		int freq = map.get(ele);
    		for(int i = index; i < index + freq; i++){
    			result[i] = ele;
    		}
    		index = index + freq;
    	}
    	return result;
    }
}