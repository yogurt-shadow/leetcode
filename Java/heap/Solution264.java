import java.util.HashSet;
import java.util.Set;
import java.util.Queue;
import java.util.PriorityQueue;
import java.util.Comparator;

class Solution264 {
   public int nthUglyNumber(int n) {
        Set<Long> set = new HashSet<>();

        Queue<Long> queue = new PriorityQueue<>();
        queue.add((long) 1);
        set.add((long) 1);
        int cur = 0;
        while(cur < n){
            long number = queue.poll();
            cur += 1;
            if(cur == n){
                return (int) number;
            }
            long n1 = number * 2;
            long n2 = number * 3;
            long n3 = number * 5;
            if(!set.contains(n1)){
                queue.add(n1);
            }
            if(!set.contains(n2)){
                queue.add(n2);
            }
            if(!set.contains(n3)){
                queue.add(n3);
            }
            set.add(n1);
            set.add(n2);
            set.add(n3);
        }
        return -1;
    }

    public static void main(String[] args){
    	Solution264 s = new Solution264();
    	System.out.println(s.nthUglyNumber(2));
    }
}