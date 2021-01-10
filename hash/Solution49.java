import java.util.*;


class Solution49 {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> map = new HashMap<>();
    	for(String str: strs){
            char[] number = str.toCharArray();
            Arrays.sort(number);
            String string = String.valueOf(number);
            if(map.containsKey(string)){
                map.get(string).add(str);
            }
            else{
                List<String> list = new LinkedList<>();
                list.add(str);
                map.put(string, list);
            }
        }

        List<List<String>> result = new LinkedList<>();
        for(List<String> list: map.values()){
            result.add(list);
        }
        return result;
    }

    public static void main(String[] args){
        Solution49 s = new Solution49();
        String[] test = new String[]{"eat", "tea", "tan", "ate", "nat", "bat"};
        List<List<String>> result = s.groupAnagrams(test);
    }

}