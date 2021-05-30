import java.util.List;
import java.util.LinkedList;

class Solution5677 {
    public int countHomogenous(String s) {
    	if(s.length() == 0){
    		return 0;
    	}
    	int x =  1000000007;
    	int size = s.length();
    	char cur = s.charAt(0);
    	int number = 0;
    	List<Integer> list = new LinkedList<>();
    	for(int i = 0; i < s.length(); i++){
    		char cur2 = s.charAt(i);
    		if(cur2 != cur){
    			cur = cur2;
    			list.add(number);
    			number = 1;
    		}
    		else{
    			number += 1;
    		}
    	}
    	list.add(number);
    	long count = 0;
    	for(int i = 0; i < list.size(); i++){
    		int cc = list.get(i);
    		long mm = (cc + (long) 1) * cc / 2;
    		count += (mm) % x;
    	}
    	return (int) count % x;
    }

    public static void main(String[] args){
    	Solution5677 s = new Solution5677();
    	System.out.println(s.countHomogenous("aadadw"));
    }
}