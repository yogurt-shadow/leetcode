import java.util.Map;
import java.util.HashMap;
import java.util.List;
import java.util.LinkedList;

class Solution30 {
    public List<Integer> findSubstring(String s, String[] words) {
    	List<Integer> result = new LinkedList<>();
    	int word_length = words[0].length();
    	int word_num = words.length;
    loop: for(int i = 0; i <= s.length() - word_num * word_length; i++){
            int j = i;
    		Map<String, Integer> map = new HashMap<>();
    		for(String str: words){
    			if(map.containsKey(str)){
    				map.put(str, map.get(str) + 1);
				}
    			else{
    				map.put(str, 1);
				}
    		}
    		while(!map.isEmpty()){
    			if(map.containsKey(s.substring(i, i + word_length))){
    				if(map.get(s.substring(i, i + word_length)) == 1){
    					map.remove(s.substring(i, i + word_length));
					}
    				else{
    					map.put(s.substring(i, i + word_length), map.get(s.substring(i, i + word_length)) - 1);
					}
    				i += word_length;
    			}
    			else{
                    i = j;
    				continue loop;
    			}
    		}
    		result.add(j);
    		 i = j;
    	}
    	return result;
    }

    public static void main(String[] args){
    	Solution30 s = new Solution30();
    	String ss = "wordgoodgoodgoodbestword";
    	String[] words = new String[]{"word", "good", "best", "good"};
    	List<Integer> result = s.findSubstring(ss, words);
    	System.out.println(result);
    }
}