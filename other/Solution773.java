import java.util.Queue;
import java.util.LinkedList;
import java.util.Set;
import java.util.HashSet;

class Solution773 {
    public int slidingPuzzle(int[][] board) {
    	int[][] direction = {
    		{1, 3},
    		{0, 2, 4},
    		{1, 5},
    		{0, 4},
    		{1, 3, 5},
    		{2, 4}
    	};
        String target = "123450";
    	Set<String> visited = new HashSet<>();
    	Queue<String> queue = new LinkedList<>();
    	int step = 0;
        queue.add(convert(board));
    	while(queue.size() > 0){
    		int cur_size = queue.size();
    		for(int i = 0; i < cur_size; i++){
    			String status = queue.poll();
                if(status.equals(target)){
                    return step;
                }
    			int zero = -1;
    			for(int index = 0; index < status.length(); index++){
    				if(status.charAt(index) == '0'){
    					zero = index;
    					break;
    				}
    			}
    			for(int k: direction[zero]){
    				String str = swap(status, zero, k);
    				if(!visited.contains(str)){
    					visited.add(str);
    					queue.add(str);
    				}
    			}
    		}
    		step += 1;
    	}
    	return -1;
    }

    private String swap(String cur, int zero, int other){
    	char[] array = cur.toCharArray();
    	array[zero] = array[other];
    	array[other] = '0';
    	return String.valueOf(array);
    }

    private String convert(int[][] board){
    	StringBuilder str = new StringBuilder();
    	for(int[] ele1: board){
    		for(int ele: ele1){
    			str.append((char) (ele + '0'));
    		}
    	}
    	return str.toString();
    }

    public static void main(String[] args){
        Solution773 s = new Solution773();
        int[][] board1 = {{3, 2, 4}, {1, 5, 0}};
        System.out.println(s.slidingPuzzle(board1));
    }
}