import java.util.List;
import java.util.LinkedList;

class Solution77 {
    public List<List<Integer>> combine(int n, int k) {
    	List<List<Integer>> result = new LinkedList<>();
    	List<Integer> list = new LinkedList<>();
    	put(result, list, 1, n, k);
    	return result;
    }

    private void put(List<List<Integer>> result, List<Integer> list, int cur, int end, int size){
   number: for(int i = 1; i <= end; i++){
    		if(list.size() > 0 && list.get(list.size() - 1) >= i){
                continue number;
            }
    		list.add(i);
    		if(cur == size){
    			List<Integer> copy = new LinkedList<>(list);
    			result.add(copy);
    			list.remove(cur - 1);
    			continue number;
    		}
    		put(result, list, cur + 1, end, size);
    		list.remove(cur - 1);
    	}
    }

    public static void main(String[] args){
    	Solution77 s = new Solution77();
    	List<List<Integer>> result = s.combine(4, 2);
    }
}