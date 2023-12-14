/**
* Solution 295
*/
import java.util.Queue;
import java.util.PriorityQueue;
import java.util.Comparator;

class MedianFinder {
	Queue<Integer> small;
	Queue<Integer> large;
	int size;
	int size1;
	int size2;
    /** initialize your data structure here. */
    public MedianFinder() {
    	size = 0;
    	size1 = 0;
    	size2 = 0;
        Comparator<Integer> cmp = (x, y) -> y - x;
    	small = new PriorityQueue<>(cmp);
    	large = new PriorityQueue<>();
	}
    
    public void addNum(int num) {
    	if(size1 == 0){
    		small.add(num);
    		size1 += 1;
    		size += 1;
    	}
    	else if(size2 == 0){
    		if(num >= small.peek()){
    			large.add(num);
    			size2 += 1;
    			size += 1;
    		}
    		else{
    			int cur = small.poll();
    			small.add(num);
    			large.add(cur);
    			size2 += 1;
    			size += 1;
    		}
    	}
    	else{
            if(size1 == size2){
                if(num <= large.peek()){
                    small.add(num);
                    size1 += 1;
                    size += 1;
                }
                else{
                    int cur = large.poll();
                    small.add(cur);
                    large.add(num);
                    size1 += 1;
                    size += 1;
                }
            }
            else{
                if(num >= small.peek()){
                    large.add(num);
                    size2 += 1;
                    size += 1;
                }
                else{
                    int cur = small.poll();
                    small.add(num);
                    large.add(cur);
                    size2 += 1;
                    size += 1;
                }
            }
    	}
    }
    
    public double findMedian() {
        if(size == 0){
            return 0;
        }
        return size % 2 == 1 ? small.peek() : (large.peek() + small.peek()) * 0.5;
    }

    public static void main(String[] args){
        MedianFinder obj = new MedianFinder();
        obj.addNum(1);
        obj.addNum(2);
        System.out.println(obj.findMedian());
        obj.addNum(3);
        System.out.println(obj.findMedian());
        
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */