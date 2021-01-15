import java.util.List;
import java.util.LinkedList;

class Solution46 {
    public List<List<Integer>> permute(int[] nums) {
    	List<List<Integer>> result = new LinkedList<>();
    	List<Integer> list = new LinkedList<>();
    	put(result, list, nums);
    	return result;
    }

    private void put(List<List<Integer>> result, List<Integer> list, int[] nums){
   loop: for(Integer ele: nums){
    		for(Integer ele2: list){
    			if(ele2 == ele){
    				continue loop;
    			}
    		}
    			list.add(ele);
    			if(list.size() == nums.length){
    				List<Integer> copy = new LinkedList<>(list);
    				result.add(copy);
    				list.remove(list.size() - 1);
    				return;
    			}
    			put(result, list, nums);
    			list.remove(list.size() - 1);
    	}
    }

    public static void main(String[] args){
    	Solution46 s = new Solution46();
    	int[] test1 = new int[]{1, 2, 3};
    	List<List<Integer>> result = s.permute(test1);
    }
}