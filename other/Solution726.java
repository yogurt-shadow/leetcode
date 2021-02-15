import java.util.Collections;
import java.util.List;
import java.util.LinkedList;
import java.util.Map;
import java.util.HashMap;

class Solution726 {
    public String countOfAtoms(String formula) {
        Map<String, Integer> map = countOfAtoms2(formula);
        List<String> list = new LinkedList<>();
        list.addAll(map.keySet());
        Collections.sort(list);
        StringBuilder str = new StringBuilder();
        for(int i = 0; i < list.size(); i++){
            String cur = list.get(i);
            str.append(cur);
            if(map.get(cur) > 1){
                str.append(map.get(cur));
            }
        }
        return str.toString();
    }

    private Map<String, Integer> countOfAtoms2(String formula){
        Map<String, Integer> map = new HashMap<>();
        String str = "";
        String number = "";
        for(int i = 0; i < formula.length(); i++){
            char cur = formula.charAt(i);
            if(cur >= 'A' && cur <= 'Z'){
                int index = i + 1;
                str = String.valueOf(cur);
                while(index < formula.length() && formula.charAt(index) >= 'a' && formula.charAt(index) <= 'z'){
                    str += formula.charAt(index);
                    index += 1;
                }
                while(index < formula.length() && formula.charAt(index) >= '0' && formula.charAt(index) <= '9'){
                    number += formula.charAt(index);
                    index += 1;
                }
                if(!map.containsKey(str)){
                    map.put(str, 0);
                }
                if(number.length() != 0){
                    map.put(str, map.get(str) + Integer.parseInt(number));
                }
                else{
                    map.put(str, map.get(str) + 1);
                }
                str = "";
                number = "";
                i = index - 1;
            }
            else if(cur == '('){
                int index = i + 1;
                int count = 1;
                while(index < formula.length()){
                    char cur2 = formula.charAt(index);
                    if(cur2 == '('){
                        count += 1;
                    }
                    if(cur2 == ')'){
                        count -= 1;
                        if(count == 0){
                            break;
                        }
                    }
                    index += 1;
                }
                String str2 = formula.substring(i + 1, index);
                Map<String, Integer> map2 = countOfAtoms2(str2);
                index += 1;
                while(index < formula.length() && formula.charAt(index) >= '0' && formula.charAt(index) <= '9'){
                    number += formula.charAt(index);
                    index += 1;
                }
                int times = 0;
                if(number.length() == 0){
                    times = 1;
                }
                else{
                    times = Integer.parseInt(number);
                }
                for(String ele: map2.keySet()){
                    if(!map.containsKey(ele)){
                        map.put(ele, 0);
                    }
                    int size = map2.get(ele);
                    map.put(ele, map.get(ele) + size * times);
                }
                number = "";
                str = "";
                i = index - 1;
               }
           }
           return map;
       }

    public static void main(String[] args){
    	Solution726 s = new Solution726();
    	System.out.println(s.countOfAtoms("K4(ON(SO3)2)2"));
    }
}