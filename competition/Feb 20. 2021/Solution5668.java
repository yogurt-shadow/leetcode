import java.util.*;

class Solution5668 {
    public String longestNiceSubstring(String s) {
    	for(int length = s.length(); length >= 0; length--){
            for(int left = 0; left + length - 1 < s.length(); left++){
                if(check(s.substring(left, left + length))){
                    return s.substring(left, left + length);
                }
            }
        }
        return "";
    }

    private boolean check(String x){
        Map<Character, Integer> map = new HashMap<>();
        for(Character ele: x.toCharArray()){
            if(!map.containsKey(ele)){
                map.put(ele, 1);
            }
            else{
                map.put(ele, map.get(ele) + 1);
            }
        }
        for(Character ele: map.keySet()){
            if(ele >= 'a' && ele <= 'z'){
                if(!map.containsKey( (char) (ele - 'a' + 'A'))){
                    return false;
                }
            }
            else{
                if(!map.containsKey((char) (ele - 'A' + 'a'))){
                    return false;
                }
            }
        }
        return true;
    }
    public static void main(String[] args){
    	Solution5668 s = new Solution5668();
    	String s2  ="Bb";
    	System.out.println(s.longestNiceSubstring(s2));
	}
}