import java.util.Queue;
import java.util.LinkedList;

class Solution239 {
    private class Monoqueue<T extends Comparable<T>>{
        private LinkedList<T> queue;
      
        public Monoqueue(){
            queue = new LinkedList<>();
        }

        private void push(T item){
            if(queue.size() == 0 || item.compareTo(queue.get(queue.size() - 1)) <= 0){
                queue.offer(item);
                return;
            }

            while(queue.size() > 0 && item.compareTo(queue.get(queue.size() - 1)) > 0){
                queue.remove(queue.size() - 1);
            }
            queue.offer(item);
        }

        private void pop(T item){
            if(queue.size() > 0 && item.compareTo(queue.peek()) == 0){
                queue.poll();
            }
        }

        private T front(){
            if(queue.size() > 0){
                return queue.peek();
            }
            return null;
        }
    }
    
    public int[] maxSlidingWindow(int[] nums, int k) {
        if(k >= nums.length){
            int max = Integer.MIN_VALUE;
            for(int ele: nums){
                max = ele > max ? ele : max;
            }
            return new int[]{max};
        }
        Monoqueue<Integer> queue = new Monoqueue<>();
        int left = 0;
        int right = k - 1;
        int[] result = new int[nums.length];
        int index = 0;
        for(int i = left; i <= right; i++){
            queue.push(nums[i]);
        }
        while(right <= nums.length - 1){
            result[index] = queue.front();
            index += 1;
            queue.pop(nums[left]);
            left += 1;
            right += 1;
            if(right <= nums.length - 1){
                queue.push(nums[right]);
            }
        }
        int[] result2 = new int[index];
        System.arraycopy(result, 0, result2, 0, index);
        return result2;
    	}

        public static void main(String[] args){
            Solution239 s = new Solution239();
            int[] test = new int[]{-7,-8,7,5,7,1,6,0};
            int[] result = s.maxSlidingWindow(test, 4);
        }
}