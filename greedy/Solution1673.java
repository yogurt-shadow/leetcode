import java.util.List;
import java.util.LinkedList;

class Solution1673 {
    public int[] mostCompetitive(int[] nums, int k) {
    	List<List<Integer>> result = new LinkedList<>();
    	List<Integer> list = new LinkedList<>();
    	put(result, list, nums, k, 0);
        List<Integer> min = result.get(0);
        for(List<Integer> ele: result){
           if(smaller(ele, min)){
             min = ele;
           }
        }
        int[] result2 = new int[k];
        for(int index = 0; index < min.size(); index++){
            result2[index] = min.get(index);
        }
        return result2;
    }

    private boolean smaller(List<Integer> list1, List<Integer> list2){
        for(int i = 0; i < list1.size(); i++){
            if(list1.get(i) < list2.get(i)){
                return true;
            }
            if(list1.get(i) > list2.get(i)){
                return false;
            }
        }
        return false;
    }


    private int convert(List<Integer> list){
        int sum = 0;
        for(int i = 0; i < list.size(); i++){
            sum = 10 * sum + list.get(i);
        }
        return sum;
    }

    private void put(List<List<Integer>> result, List<Integer> list, int[] nums, int k, int start){
    	if(start >= nums.length){
    		return;
    	}
    	for(int i = start; i < nums.length; i++){
    		list.add(nums[i]);
    		if(list.size() == k){
    			List<Integer> copy = new LinkedList<>(list);
    			result.add(copy);
    			list.remove(list.size() - 1);
    			continue;
    		}
    		put(result, list, nums, k, i + 1);
    		list.remove(list.size() - 1);
    	}
    }

    public static void main(String[] args){
    	Solution1673 s = new Solution1673();
    	int[] result = s.mostCompetitive(new int[]{71,18,52,29,55,73,24,42,66,8,80,2}, 3);
    }
}