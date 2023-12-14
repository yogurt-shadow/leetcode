import java.util.Set;
import java.util.HashSet;
import java.util.List;
import java.util.LinkedList;
import java.util.Map;
import java.util.HashMap;


class WordDictionary {
    /** Solution 211 */
	private Map<Integer, Set<String>> map;
    /** Initialize your data structure here. */
    public WordDictionary() {
    	map = new HashMap<>();
    }
    
    /** Adds a word into the data structure. */
    public void addWord(String word) {
    	if(!map.containsKey(word.length())){
            map.put(word.length(), new HashSet<>());
        }
        map.get(word.length()).add(word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    public boolean search(String word) {
        if(!map.containsKey(word.length())){
            return false;
        }
    	List<Integer> dot = new LinkedList<>();
        boolean hasdot = false;
    	for(int i = 0; i < word.length(); i++){
    		char cur = word.charAt(i);
    		if(cur == '.'){
                hasdot = true;
    			dot.add(i);
    		}
    	}
        if(!hasdot){
            return map.get(word.length()).contains(word);
        }
    	Set<String> set2 = new HashSet<>();
    	dotconvert(set2, word, dot, 0);
    	for(String ele: map.get(word.length())){
    		if(set2.contains(ele)){
    			return true;
    		}
    	}
    	return false;
    }

    private void dotconvert(Set<String> set2, String word, List<Integer> dot, int index){
    	for(char cur = 'a'; cur <= 'z'; cur++){
    		char[] array = word.toCharArray();
    		array[dot.get(index)] = cur;
    		String str = String.valueOf(array);
    		if(index == dot.size() - 1){
    			set2.add(str);
    			continue;
    		}
    		dotconvert(set2, str, dot, index + 1);
    	}
    }

    public static void main(String[] args){
    	WordDictionary w = new WordDictionary();
    	Set<String> set2 = new HashSet<>();
    	List<Integer> dot = new LinkedList<>();
    	dot.add(2);
    	dot.add(3);
    	w.dotconvert(set2, "ab..z", dot, 0);
    }
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * boolean param_2 = obj.search(word);
 */