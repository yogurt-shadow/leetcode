import java.util.*;

class Solution5686 {
    public int[] minOperations(String boxes) {
    	Set<Integer> set = new HashSet<>();
    	for(int i = 0; i < boxes.length(); i++){
    		if(boxes.charAt(i) == '1'){
    			set.add(i);
    		}
    	}
    	int[] result = new int[boxes.length()];
    	for(int i = 0; i < boxes.length(); i++){
    		int cur = 0;
    		for(Integer ele: set){
    			cur += Math.abs(ele - i);
    		}
    		result[i] = cur;
    	}
    	return result;
    }
}