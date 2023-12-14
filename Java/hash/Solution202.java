import java.util.Set;
import java.util.HashSet;

class Solution202 {
    public boolean isHappy(int n) {
    	Set<Integer> set = new HashSet<>();
    	while(n != 1){
    		n = sumof(n);
    		if(set.contains(n)){
    			return false;
    		}
    		else{
    			set.add(n);
    		}
    	}
    	return true;

    }

    private int sumof(int x){
    	int sum = 0;
    	while(x != 0){
    		sum += Math.pow(x % 10, 2);
    		x = x / 10;
    	}
    	return sum;
    }
}