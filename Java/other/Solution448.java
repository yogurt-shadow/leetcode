import java.util.List;
import java.util.LinkedList;

class Solution448 {
    public List<Integer> findDisappearedNumbers(int[] nums) {
    	int n = nums.length;
    	int[] array = new int[n + 1];
    	for(int ele: nums){
    		array[ele] += 1;
    	}
    	List<Integer> list = new LinkedList<>();
    	for(int i = 1; i <= n; i++){
    		if(array[i] == 0){
    			list.add(i);
    		}
    	}
    	return list;
    }
}