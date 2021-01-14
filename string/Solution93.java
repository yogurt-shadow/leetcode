import java.util.List;
import java.util.LinkedList;

class Solution93 {
    public List<String> restoreIpAddresses(String s) {
    	List<String> result = new LinkedList<>();
    	if(s.length() < 4 || s.length() > 12){
    		return result;
    	}
    	List<List<Integer>> choice = new LinkedList<>();
    	List<Integer> list = new LinkedList<>();
    	put(choice, list, 0, s.length());
   loop: 	for(List<Integer> ele: choice){
    		int sum = 0;
    		List<String> l = new LinkedList<>();
    		for(Integer ele2: ele){
    			String str = s.substring(sum, sum + ele2);
    			if( (str.length() > 1 && str.charAt(0) == '0') || Integer.parseInt(str) > 255){
    				continue loop;
    			}
    			sum = sum + ele2;
    			l.add(str);
    		}
    		String cur = "";
    		for(String strrrr: l){
    			cur = cur + strrrr + ".";
    		}
    		result.add(cur.substring(0, cur.length() - 1));
    	}
    	return result;

    }

    private void put(List<List<Integer>> result, List<Integer> store, int index, int length){
    	for(int i = 1; i <= 3; i++){
    		store.add(i);
    		if(index == 3){
    			int sum = 0;
    			for(Integer ele: store){
    				sum += ele;
    			}
    			if(sum == length){
    				List<Integer> copy = new LinkedList<>();
    				for(Integer eee: store){
    					copy.add(eee);
					}
    				result.add(copy);
    				store.remove(index);
    				return;
    			}
    		}
    		else {
				put(result, store, index + 1, length);
			}
    		store.remove(index);
    	}
    }

    public static void main(String[] args){
    	Solution93 s = new Solution93();
    	List<String> result = s.restoreIpAddresses("0000");
    	System.out.println(result);
    }
}