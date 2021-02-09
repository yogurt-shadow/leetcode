import java.util.PriorityQueue;
import java.util.Queue;

class KthLargest {
	Queue<Integer> queue;
	int size;
	int k;

    public KthLargest(int k, int[] nums) {
    	queue = new PriorityQueue<>();
    	for(int ele: nums){
    		queue.add(ele);
    	}
    	while(queue.size() > k){
    		queue.poll();
    	}
    	size = queue.size();
    	this.k = k;
    }
    
    public int add(int val) {
    	if(size < k){
    		queue.add(val);
            size += 1;
    	}
    	else{
    		if(val > queue.peek()){
    			queue.poll();
    			queue.add(val);
    		}
    	}
    	return queue.peek();
    }
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */