import java.util.*;

class Solution5690 {
    public int closestCost(int[] baseCosts, int[] toppingCosts, int target) {
    	int result = Integer.MAX_VALUE;
    	int dist = Integer.MAX_VALUE;
    	int[] copy = new int[2 * toppingCosts.length];
    	System.arraycopy(toppingCosts, 0, copy, 0, toppingCosts.length);
    	System.arraycopy(toppingCosts, 0, copy, toppingCosts.length, toppingCosts.length);
    	Arrays.sort(copy);
    	for(int i = 0; i < baseCosts.length; i++){
    		int cur = baseCosts[i] + close(copy, target - baseCosts[i]);
    		if(Math.abs(cur - target) < dist){
    			dist = Math.abs(cur - target);
    			result = cur;
    		}
    		else if(Math.abs(cur - target) == dist && cur < result){
    			result = cur;
    		}
    		if(dist == 0){
    			break;
    		}
    	}
    	return result;
    }

    private int close(int[] array, int target){
    	int result = 0;
    	int dist = target;
    	if(array.length == 0){
    		return 0;
		}
    	if(array[0] >= target){
            if(Math.abs(target - array[0]) < dist){
            	dist = Math.abs(target - array[0]);
            	result = array[0];
			}
            return result;
        }
        int[] copy = new int[array.length - 1];
        System.arraycopy(array, 1, copy, 0, copy.length);
        int res1 = close(copy, target);
        int res2 = close(copy, target - array[0]) + array[0];
        if(Math.abs(res1 - target) < dist){
        	dist = Math.abs(res1 - target);
        	result = res1;
		}
		else if(Math.abs(res1 - target) == dist){
			result = Math.min(result, res1);
		}
		if(Math.abs(res2 - target) < dist){
			dist = Math.abs(res2 - target);
			result = res2;
		}
		else if(Math.abs(res2 - target) == dist){
			result = Math.min(result, res2);
		}
    	return result;
    }


    public static void main(String[] args){
    	Solution5690 s = new Solution5690();
    	int[] test1 = {3, 10};
    	int[] test2 = {2, 5};
    	System.out.println(s.closestCost(test1, test2, 9));
	}
}