import java.util.List;
import java.util.LinkedList;

class Solution118 {
    public List<List<Integer>> generate(int numRows) {
    	if(numRows == 0){
    		List<List<Integer>> result = new LinkedList<>();
    		return result;
    	}
    	if(numRows == 1){
    		List<List<Integer>> result = new LinkedList<>();
    		List<Integer> list = new LinkedList<>();
    		list.add(1);
    		result.add(list);
    		return result;
    	}
    	List<List<Integer>> list = generate(numRows - 1);
    	int index = 0;
    	List<Integer> last = list.get(list.size() - 1);
    	List<Integer> cur = new LinkedList<>();
    	cur.add(1);
    	while(index + 1 < last.size()){
    		cur.add(last.get(index) + last.get(index + 1));
    		index += 1;
    	}
    	cur.add(1);
    	list.add(cur);
    	return list;
    }

    public static void main(String[] args){
    	Solution118 s = new Solution118();
    	List<List<Integer>> result = s.generate(5);
    	for(List<Integer> ele: result){
    		System.out.println(ele);
    	}
    }
}