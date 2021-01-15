import java.util.Map;
import java.util.HashMap;
import java.util.List;
import java.util.LinkedList;

class Solution90 {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
    	List<List<Integer>> result = new LinkedList<>();
    	List<Integer> list = new LinkedList<>();
    	put(result, list, nums, 0);
    	List<Integer> empty = new LinkedList<>();
    	result.add(empty);
    	return result;
    }

    private void put(List<List<Integer>> result, List<Integer> list, int[] nums, int index){
    loop2: for(int i = index; i < nums.length; i++){
    		list.add(nums[i]);
    	loop: for(List<Integer> ele: result){
    			if(ele.size() == list.size()){
    				if(totalequal(ele, list)){
    					list.remove(list.size() - 1);
    					continue loop2;
    				}
    			}
    		}
    		List<Integer> copy = new LinkedList<>(list);
    		result.add(copy);
    		put(result, list, nums, i + 1);
    		list.remove(list.size() - 1);
    	}
    }

    private boolean totalequal(List<Integer> list1, List<Integer> list2){
    	Map<Integer, Integer> map = new HashMap<>();
    	for(Integer ele1: list1){
    		if(map.containsKey(ele1)){
    			map.put(ele1, map.get(ele1) + 1);
    		}
    		else{
    			map.put(ele1, 1);
    		}
    	}

    	for(Integer ele2: list2){
    		if(!map.containsKey(ele2)){
    			return false;
    		}
    		map.put(ele2, map.get(ele2) - 1);
    	}
    	for(Integer ele: map.keySet()){
            if(map.get(ele) != 0){
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args){
    	Solution90 s = new Solution90();
    	int[] test = new int[]{4, 4, 4, 1, 4};
    	List<List<Integer>> result = s.subsetsWithDup(test);
    }
}