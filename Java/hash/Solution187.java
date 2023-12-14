import java.util.Map;
import java.util.HashMap;
import java.util.List;
import java.util.LinkedList;

class Solution187 {
    public List<String> findRepeatedDnaSequences(String s) {
    	Map<String, Integer> map = new HashMap<>();
    	for(int i = 0; i < s.length() - 9; i++){
    		String cur = s.substring(i, i + 10);
    		if(map.containsKey(cur)){
    			map.put(cur, map.get(cur) + 1);
    		}
    		else{
    			map.put(cur, 1);
    		}
    	}
    	List<String> result = new LinkedList<>();
    	for(String str: map.keySet()){
    		if(map.get(str) > 1){
    			result.add(str);
    		}
    	}
    	return result;
    }
}