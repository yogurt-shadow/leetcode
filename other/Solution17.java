import java.util.Map;
import java.util.HashMap;
import java.util.List;
import java.util.LinkedList;

class Solution17 {
	Map<Character, char[]> key;


    public List<String> letterCombinations(String digits) {
        if(digits.length() == 0){
            return new LinkedList<String>();
        }
    	key = new HashMap<>();
    	key.put('1', new char[]{'!', '@', '#'});
    	key.put('2', new char[]{'a', 'b', 'c'});
    	key.put('3', new char[]{'d','e','f'});
    	key.put('4', new char[]{'g', 'h', 'i'});
    	key.put('5', new char[]{'j', 'k', 'l'});
    	key.put('6', new char[]{'m', 'n', 'o'});
    	key.put('7', new char[]{'p', 'q', 'r', 's'});
    	key.put('8', new char[]{'t', 'u', 'v'});
    	key.put('9', new char[]{'w', 'x', 'y', 'z'});

    	List<String> result = new LinkedList<>();
    	if(digits.length() == 1){
    		char[] current = key.get((digits.charAt(0)));
    		String s = "";
    		for(int i = 0; i < current.length; i++){
    			result.add(s + current[i]);
    		}
    		return result;
    	}

        String former = digits.substring(0, digits.length() - 1);
        for(String rr: letterCombinations(former)){
            for(int i = 0; i < key.get(digits.charAt(digits.length() - 1)).length; i++){
                result.add(rr + key.get(digits.charAt(digits.length() - 1))[i]);
            }
        }
        return result;
    	
    }

    public static void main(String[] args){
    	Solution17 s = new Solution17();
    	for(String result: s.letterCombinations("23")){
    		System.out.println(result);
    	}
    }
}