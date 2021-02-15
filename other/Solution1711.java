import java.util.*;

class Solution1711 {
    public int countPairs(int[] deliciousness) {
    	Map<Integer, Integer> map = new HashMap<>();
    	long count = 0;
    	final int mod = 1000000000 + 7;
    	for(int i = 0; i < deliciousness.length; i++){
    		int ele = deliciousness[i];
    		int pow = 1;
    		for(int k = 0; k <= 21; k++){
    			int other = pow - ele;
    			if(map.containsKey(other)){
    				count += map.get(other);
    			}
    			pow = pow << 1;
    		}
    		if(map.containsKey(ele)){
    			map.put(ele, map.get(ele) + 1);
    		}
    		else{
    			map.put(ele, 1);
    		}
    	}
    	return (int) (count % mod);
    }
    public static void main(String[] args){
        Solution1711 s = new Solution1711();
        int[] test = {1,3,5,7,9};
        System.out.println(s.countPairs(test));
    }
}