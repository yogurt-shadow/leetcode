import java.util.Set;
import java.util.HashSet;
import java.util.Queue;
import java.util.PriorityQueue;

class Solution313 {
    public int nthSuperUglyNumber(int n, int[] primes) {
    	Set<Long> set = new HashSet<>();
    	Queue<Long> pq = new PriorityQueue<>();
    	int index = 0;
    	pq.add((long) 1);
    	set.add((long) 1);

    	while(index < n){
    		long cur = pq.poll();
    		index += 1;
    		if(index == n){
    			return (int) cur;
			}
    		for(int j = 0; j < primes.length; j++) {
				if (!set.contains(cur * primes[j])) {
					set.add(cur * primes[j]);
					pq.add(cur * primes[j]);
				}
			}
    	}
    	return -1;
    }

    public static void main(String[] args){
    	Solution313 s = new Solution313();
    	System.out.println(s.nthSuperUglyNumber(12, new int[]{2, 7, 13, 19}));
	}
}