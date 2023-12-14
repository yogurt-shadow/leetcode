import java.util.List;
import java.util.LinkedList;

class Solution165 {
    public int compareVersion(String version1, String version2) {
    	List<Integer> list1 = convert(version1);
    	List<Integer> list2 = convert(version2);
    	return compare(list1, list2);
    }

    private int compare(List<Integer> list1, List<Integer> list2){
    	for(int i = 0; i < list1.size(); i++){
    		if(list2.size() <= i){
    			if(list1.get(i) > 0){
    				return 1;
				}
    			continue;
    		}
    		int left = list1.get(i);
    		int right = list2.get(i);
    		if(left != right){
    			return left > right ? 1 : -1;
    		}
    	}
    	if(list2.size() <= list1.size()){
            return 0;
        }

    	for(int j = list1.size(); j < list2.size(); j++){
            if(list2.get(j) > 0){
                return -1;
            }
        }
        return 0;
    }

    private List<Integer> convert(String str){
    	List<Integer> list = new LinkedList<>();
    	String number = "";
    	for(int i = 0; i < str.length(); i++){
    		char cur = str.charAt(i);
    		if(cur >= '0' && cur <= '9'){
    			number += cur;
    		}
    		
    		if(i == str.length() - 1){
    			list.add(Integer.parseInt(number));
    		}

    		if(cur == '.'){
    			list.add(Integer.parseInt(number));
    			number = "";
    		}
    	}
    	return list;
    }

    public static void main(String[] args){
    	Solution165 s = new Solution165();
    	System.out.println(s.compareVersion("1.01", "1.001"));
		System.out.println(s.compareVersion("1.0", "1.0.0"));
		System.out.println(s.compareVersion("0.1", "1.1"));
		System.out.println(s.compareVersion("1.0.1", "1"));
		System.out.println(s.compareVersion("7.5.4.2", "7.5.3"));
		System.out.println(s.compareVersion("1.0", "1"));

	}
}