import java.util.Queue;
import java.util.PriorityQueue;

class Solution659 {
    public boolean isPossible(int[] nums) {
    	Queue<Integer>[] length = new PriorityQueue[10000];
    	for(int i = 0; i < 10000; i++){
    		length[i] = new PriorityQueue<>();
    	}

    	for(int i = 0; i < nums.length; i++){
    		int cur = nums[i];
    		if(length[cur - 1 + 2000].size() == 0){
    			length[cur + 2000].add(1);
    		}

    		else{
    			int x = length[cur + 2000 - 1].poll();
    			length[cur + 2000].add(x + 1);
    		}
    	}

    	for(int i = 0; i < 10000; i++){
    		if(length[i].size() > 0 && length[i].peek() < 3){
    			return false;
    		}
    	}
    	return true;
    }

    public static void main(String[] args){
    	Solution659 s = new Solution659();
    	int[] test1 = new int[]{1, 2, 3, 4, 4, 5};
    	System.out.println(s.isPossible(test1));
    }
}