import java.util.*;


class Solution5665 {
    public int[] restoreArray(int[][] adjacentPairs) {
    	Map<Integer, List<Integer>> map = new HashMap<>();
    	Set<Integer> set = new HashSet<>();
    	for(int[] ele: adjacentPairs){
    		if(!map.containsKey(ele[0])){
    			map.put(ele[0], new LinkedList<>());
    		}
    		if(!map.containsKey(ele[1])){
    			map.put(ele[1], new LinkedList<>());
    		}
    		map.get(ele[1]).add(ele[0]);
    		map.get(ele[0]).add(ele[1]);
    	}
    	int head = -1;
    	for(Integer ele: map.keySet()){
    		if(map.get(ele).size() == 1){
    			head = ele;
    			break;
    		}
    	}
    	int[] result = new int[adjacentPairs.length + 1];
    	result[0] = head;
    	set.add(head);
    	int index = 1;
    	while(index < result.length){
    		List<Integer> list = map.get(head);
    		for(Integer ele: list){
    			if(!set.contains(ele)){
    				set.add(ele);
    				result[index] = ele;
    				index += 1;
    				head = ele;
    			}
    		}
    	}
    	return result;
	}

    public static void main(String[] args){
    	Solution5665 s = new Solution5665();
    	int[][] test = {{2, 1}, {3, 4}, {3, 2}};
    	System.out.println(s.restoreArray(test)[0]);
    }
}