import java.util.Map;
import java.util.HashMap;

class Solution290 {
    public boolean wordPattern(String pattern, String s) {
    	String [] arr = s.split("\\s+");
    	if(pattern.length() != arr.length){
    		return false;
    	}
    	Map<Character, String> map1 = new HashMap<>();
    	Map<String, Character> map2 = new HashMap<>();
    	for(int i = 0; i < pattern.length(); i++){
    		char left = pattern.charAt(i);
    		String right = arr[i];
    		if(map1.containsKey(left)){
    			if(!map1.get(left).equals(right)){
    				return false;
    			}
    			continue;
    		}
    		if(map2.containsKey(right)){
    			return false;
    		}
    		map1.put(left, right);
    		map2.put(right, left);
    	}
    	return true;
    }

    public static void main(String[] args){
    	Solution290 s = new Solution290();
    	System.out.println(s.wordPattern("abba", "dog cat cat dog"));
    }
}