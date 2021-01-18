import java.util.Map;
import java.util.HashMap;


class Solution1726 {
    public int tupleSameProduct(int[] nums) {
    		Map<Integer, Integer> map = new HashMap<>();
    		for(int i = 0; i < nums.length; i++){
    			for(int j = i + 1; j < nums.length; j++){
    				int times = nums[i] * nums[j];
    				if(!map.containsKey(times)){
    					map.put(times, 1);
    				}
    				else{
    					map.put(times, map.get(times) + 1);
    				}
    			}
    		}
    		int count = 0;
    		for(Integer times: map.keySet()){
    			count += map.get(times) * (map.get(times) - 1) / 2;
    		}
    		return 8 * count;
    	}
        
    public static void main(String[] args){
    	Solution1726 s = new Solution1726();
    	int[] test1 = new int[]{2, 3, 4, 6};
    	System.out.println(s.tupleSameProduct(test1));
    }
}