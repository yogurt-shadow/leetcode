import java.util.Set;
import java.util.HashSet;

class Solution349 {
    public int[] intersection(int[] nums1, int[] nums2) {
    	Set<Integer> set = new HashSet<>();
    	for(int i = 0; i < nums1.length; i++){
    		if(!set.contains(nums1[i])){
    			set.add(nums1[i]);
    		}
    	}
    	int[] result = new int[nums2.length];
    	int index = 0;
    	for(int j = 0; j < nums2.length; j++){
    		if(set.contains(nums2[j])){
    			result[index] = nums2[j];
    			index += 1;
    			set.remove(nums2[j]);
    		}
    	}

    	int[] result2 = new int[index];
    	System.arraycopy(result, 0, result2, 0, index);
    	return result2;
    }
}