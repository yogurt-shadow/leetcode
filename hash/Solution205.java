import java.util.Map;
import java.util.HashMap;

class Solution205 {
    public boolean isIsomorphic(String s, String t) {
    	if(s.length() != t.length()){
    		return false;
    	}
    	return isIsomorphic2(s, t) && isIsomorphic2(t, s);
    }

    private boolean isIsomorphic2(String s, String t){
    	Map<Character, Character> map = new HashMap<>();
    	for(int i = 0; i < s.length(); i++){
    		char left = s.charAt(i);
    		char right = t.charAt(i);
    		if(!map.containsKey(left)){
    			map.put(left, right);
    		}
    		else{
    			if(map.get(left) != right){
    				return false;
    			}
    		}
    	}
    	return true;
    }

    public static void main(String[] args){
    	Solution205 s = new Solution205();
    	String test11 = "egg";
    	String test12 = "add";
    	System.out.println(s.isIsomorphic(test11, test12));
    	String test21 = "foo";
    	String test22 = "bar";
    	System.out.println(s.isIsomorphic(test21, test22));
    }
}