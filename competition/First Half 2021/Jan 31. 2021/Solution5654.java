import java.util.*;

class Solution5654 {
    public int countBalls(int lowLimit, int highLimit) {
    	Map<Integer, Integer> map = new HashMap<>();
    	int max = 1;
        int index = 1;

    	for(int i = lowLimit; i <= highLimit; i++){
    		int sum = sum(i);
    		if(!map.containsKey(sum)){
    			map.put(sum, 1);
    		}
    		else{
    			map.put(sum, map.get(sum) + 1);
    			if(map.get(sum) > max){
                    max = map.get(sum);
                    index = sum;
                }
    		}
    	}
    	return max;
    }

    private int sum(int x){
    	int result = 0;
    	while(x != 0){
    		result += x % 10;
    		x = x / 10;
    	}
    	return result;
    }

    public static void main(String[] args){
    	Solution5654 s = new Solution5654();
    	System.out.println(s.countBalls(5, 15));
    }
}