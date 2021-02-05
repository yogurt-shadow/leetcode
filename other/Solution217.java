import java.util.Set;
import java.util.HashSet;

class Solution217 {
    public boolean containsDuplicate(int[] nums) {
    	Set<Integer> set = new HashSet<>();
    	for(int ele: nums){
    		if(set.contains(ele)){
    			return true;
    		}
    		set.add(ele);
    	}
    	return false;
    }
}