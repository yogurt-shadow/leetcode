import java.util.List;
import java.util.LinkedList;

class Solution91 {
    public int numDecodings(String s) {
    	List<List<String>> choice = new LinkedList<>();
    	List<String> list = new LinkedList<>();
    	put(choice, list, 0, s);
    	int x = 0;
   loop: for(List<String> ele: choice){
    		for(String str: ele){
    			if((str.length() == 2 && str.charAt(0) == '0') || Integer.parseInt(str) > 26 || Integer.parseInt(str) < 1){
    				continue loop;
    			}
    		}
    		x += 1;
    	}
    	return x;
    }

    private void put(List<List<String>> result, List<String> list, int total, String str){
    	for(int i = 1; i <= 2; i++){
    		list.add(str.substring(total, total + i));
    		if(total + i == str.length()){
    			List<String> copy = new LinkedList<>();
    			for(String ele: list){
    				copy.add(ele);
    			}
    			result.add(copy);
    			list.remove(list.size() - 1);
    			return;
    		}

    		put(result, list, total + i, str);
    		list.remove(list.size() - 1);
    	}
    }

    public static  void main(String[] args){
    	Solution91 s = new Solution91();
    	System.out.println(s.numDecodings("226"));
		System.out.println(s.numDecodings("12"));
		System.out.println(s.numDecodings("026"));
		System.out.println(s.numDecodings("206"));
	}
}