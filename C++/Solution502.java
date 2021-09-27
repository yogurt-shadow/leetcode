import java.util.*;

class Solution502 {
    public int findMaximizedCapital(int k, int w, int[] profits, int[] capital) {
        int size = profits.length;
        int[][] items = new int[size][2];
        for(int i = 0; i < size; i++){
            items[i][0] = capital[i];
            items[i][1] = profits[i];
        }
        Arrays.sort(items, (a, b) -> a[0] - b[0]);
        int index = 0;
        Queue<Integer> pq = new PriorityQueue<>(
            new Comparator<>(){
                @Override
                public int compare(Integer x, Integer y){
                    return y - x;
                }
            }
        );
        while(k > 0){
            while(index < size && items[index][0] <= w){
                pq.offer(items[index][1]);
                index ++;
            }
            if(pq.isEmpty()){
                return w;
            }
            w += pq.poll();
            k --;
        }
        return w;
    }

    public static void main(String[] args){
        Solution502 s = new Solution502();
        s.findMaximizedCapital(2, 2, new int[]{0, 1}, new int[]{1, 0});
    }
}