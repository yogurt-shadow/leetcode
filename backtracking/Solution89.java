import java.util.Set;
import java.util.HashSet;
import java.util.List;
import java.util.LinkedList;

class Solution89 {
    public List<Integer> grayCode(int n) {
    	List<Integer> result = new LinkedList<>();
    	Set<String> set = new HashSet<>();
    	String str = "0";
    	str = str.repeat(n);
        result.add(0);
        set.add(str);
    	put(result, str, set, n);
    	return result;
    }

    private boolean put(List<Integer> result, String str, Set<String> set, int n){
    	for(int i = n - 1; i >= 0; i--){
    		String str2 = twoandone(str, i);
    		if(set.contains(str2)){
    			continue;
    		}
    		set.add(str2);
    		result.add(convert(str2));
    		if(result.size() == (int) Math.pow(2, n)){
                return true;
            }
            if(put(result, str2, set, n)){
                return true;
            }
    	}
        return false;
    }

    private String twoandone(String str, int x){
    	StringBuilder result = new StringBuilder();
    	for(int i = 0; i < str.length(); i++){
    		char cur = str.charAt(i);
    		if(i == x){
    			result.append((char) ('1' + '0' - cur));
    		}
    		else{
    			result.append(cur);
    		}
    	}
    	return result.toString();
    }

    private int convert(String s){
    	int sum = 0;
    	for(int i = s.length() - 1; i >= 0; i--){
    		char cur = s.charAt(i);
    		sum = cur == '1' ? sum + (int) Math.pow(2, s.length() - 1 - i) : sum;
    	}
    	return sum;
    }

    public static void main(String[] args){
    	Solution89 s = new Solution89();
    	List<Integer> result = s.grayCode(2);
	}
}