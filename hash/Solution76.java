import java.util.Arrays;
import java.util.Map;
import java.util.HashMap;

class Solution76 {
    public String minWindow(String s, String t) {
    	int left = 0;
    	int right = 0;
    	int left_index = -1;
    	int min_length = Integer.MAX_VALUE;
    	int right_index = -1;
        Map<Character, Integer> t_map = new HashMap<>();
        for(char ele: t.toCharArray()){
            if(t_map.containsKey(ele)){
                t_map.put(ele, t_map.get(ele) + 1);
            }
            else{
                t_map.put(ele, 1);
            }
        }

        Map<Character, Integer> have = new HashMap<>();
        have.put(s.charAt(0), 1);
    	loop: while(left < s.length() && right < s.length()){
                if(right - left + 1 < t.length()){
                    right += 1;
                    if(right < s.length()){
                        char add = s.charAt(right);
                        if(have.containsKey(add)){
                            have.put(add, have.get(add) + 1);
                        }
                        else{
                            have.put(add, 1);
                        }
                    }
                }

                else{
                    for(Character ele: t_map.keySet()){
                        if(!have.containsKey(ele) || have.get(ele) < t_map.get(ele)){
                             right += 1;
                    if(right < s.length()){
                        char add = s.charAt(right);
                        if(have.containsKey(add)){
                            have.put(add, have.get(add) + 1);
                        }
                        else{
                            have.put(add, 1);
                        }
                        }
                        continue loop;
                    }
                }
                int length = right - left + 1;
                if(length < min_length){
                    min_length = length;
                    left_index = left;
                    right_index = right;
                }
                left += 1;
                char remove = s.charAt(left - 1);
                have.put(remove, have.get(remove) - 1);
            }
    }
    if(left_index == -1){
        return "";
    }

    return s.substring(left_index, right_index + 1);

}


    public static void main(String[] args){
        Solution76 s = new Solution76();
        /**
        String test11 = "aAbcs";
        String test12 = "bAscasic";
        String test13 = "bascsica";
        System.out.println(s.consist(test12, test11));
        System.out.println(s.consist(test13, test11));
        */
        String s1 = "ADOBECODEBANC";
        String t1 = "ABC";
        System.out.println(s.minWindow(s1, t1));
        String s2 = "a";
        String t2 = "a";
        System.out.println(s.minWindow(s2, t2));
    }
}