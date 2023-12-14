import java.util.Queue;
import java.util.PriorityQueue;

import java.util.Comparator;

import java.util.Map;
import java.util.HashMap;


class Solution347 {
    public int[] topKFrequent(int[] nums, int k) {
    	Map<Integer, Integer> map = new HashMap<>();
    	
    	Comparator<Integer> cmp = new Comparator<>(){
    		public int compare(Integer x, Integer y){
    			return map.get(y) - map.get(x);
    		}
    	};

    	Queue<Integer> pq = new PriorityQueue<>(cmp);
    	for(int i = 0; i < nums.length; i++){
    		if(map.containsKey(nums[i])){
    			map.put(nums[i], map.get(nums[i]) + 1);
    			pq.remove(nums[i]);
    			pq.add(nums[i]);
    		}

    		else{
    			map.put(nums[i], 1);
    			pq.add(nums[i]);
    		}
    	}

    	int index = 0;
    	int[] result = new int[k];
    	while(index < k){
    		result[index] = pq.poll();
    		index += 1;
    	}
    	return result;
    }

    public static void main(String[] args){
    	
    	Solution347 s = new Solution347();
    	int[] test1 = new int[]{1,1,1,2,2,3};
    	int[] output1 = s.topKFrequent(test1, 2);
    	for(int i = 0; i < output1.length; i++){
    		System.out.println(output1[i]);
    	}
    	
    	

    }
}