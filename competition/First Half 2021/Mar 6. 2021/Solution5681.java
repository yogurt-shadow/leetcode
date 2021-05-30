import java.util.*;

class Solution5681 {
    public boolean checkPowersOfThree(int n) {
    	Set<Integer> set = new HashSet<>();
    	for(int i = 0; i < (1 << 15); i++){
    		int x = 0;
    		for(int j = 0; j < 15; j++){
    			if(((1 << j) & i) != 0){
    				x += Math.pow(3, j);
    			}
    		}
    		set.add(x);
    	}
    	return set.contains(n);
    }

    public static void main(String[] args){
    	Solution5681 s = new Solution5681();
    	System.out.println(s.checkPowersOfThree(21));
    }
}