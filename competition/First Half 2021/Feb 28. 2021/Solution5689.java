import java.util.*;

class Solution5689 {
    public int countMatches(List<List<String>> items, String ruleKey, String ruleValue) {
    	int result = 0, index = 0;
    	if(ruleKey.equals("color")){
    		index = 1;
    	}
    	if(ruleKey.equals("name")){
    		index = 2;
    	}
    	for(List<String> ele: items){
    		if(ele.get(index).equals(ruleValue)){
    			result++;
    		}
    	}
    	return result;
    }
}