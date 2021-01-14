import java.util.List;
import java.util.LinkedList;

class Solution216 {
    public List<List<Integer>> combinationSum3(int k, int n) {
    	List<List<Integer>> result = new LinkedList<>();
    	List<Integer> list = new LinkedList<>();
    	put(result, list, 1, k, n);
    	return result; 
    }

    private void put(List<List<Integer>> result, List<Integer> list, int cur, int number, int sum){
    	for(int i = 1; i <= 9; i++){
    		if(list.size() > 0 && list.get(list.size() - 1) >= i){
    			continue;
    		}
    		list.add(i);
    		if(cur == number){
    			int x = 0;
    			for(Integer ele: list){
    				x += ele;
    			}
    			if(x == sum){
    				List<Integer> copy = new LinkedList<>(list);
    				result.add(copy);
    				list.remove(cur - 1);
    				return;
    			}
    			list.remove(cur - 1);
    			continue;
    		}
    		put(result, list, cur + 1, number, sum);
    		list.remove(cur - 1);
    	}
    }

    public static void main(String[] args){
    	Solution216 s = new Solution216();
    	List<List<Integer>> result = s.combinationSum3(3, 9);
    }
}