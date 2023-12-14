import java.util.Set;
import java.util.HashSet;
import java.util.Queue;
import java.util.PriorityQueue;
import java.util.Comparator;

class Solution406 {
    public int[][] reconstructQueue(int[][] people) {
    	 int[][] result = new int[people.length][2];
    	 Comparator<Integer> cmp = new Comparator<>(){
    	 	public int compare(Integer x, Integer y){
    	 		return people[x][0] - people[y][0];
    	 	}
    	 };
    	Set<Integer> set = new HashSet<>();
        Queue<Integer> pq = new PriorityQueue<>(cmp);
    	int index = 0;
    	while(index < people.length){
    	 	for(int i = 0; i < people.length; i++){
    	 		int[] cur = people[i];
    	 		if(!set.contains(i) && match(result, index, cur) && !pq.contains(i)){
    	 			pq.add(i);
    	 		}
    	 	}
    	 	int[] element = people[pq.poll()];
    	 	result[index] = element;
    	 	index += 1;
    	 	set.add(index(people, element));
    	 }
    	 return result;
    }

    private int index(int[][] people, int[] ele){
    	for(int i = 0; i < people.length; i++){
    		if(people[i] == ele){
    			return i;
    		}
    	}
    	return -1;
    }

    private boolean match(int[][] result, int index, int[] cur){
    	int sum = 0;
    	for(int i = 0; i < index; i++){
    		if(result[i][0] >= cur[0]){
    			sum += 1;
    		}
    	}
    	return sum == cur[1];
    }

    public static void main(String[] args){
    	Solution406 s = new Solution406();
    	int[][] people1 = new int[][]{new int[]{7, 0}, new int[]{4, 4}, new int[]{7, 1}, new int[]{5, 0}, new int[]{6, 1}, new int[]{5, 2}};
    	int[][] result1 = s.reconstructQueue(people1);
    	for(int i = 0; i < result1.length; i++){
    		for(int j = 0; j < 2; j++){
    			System.out.print(result1[i][j] + " ");
    		}
    		System.out.println();
    	}

    	int[][] people2 = new int[][]{new int[]{6, 0}, new int[]{5, 0}, new int[]{4, 0}, new int[]{3, 2}, new int[]{2, 2}, new int[]{1, 4}};
    	int[][] result2 = s.reconstructQueue(people2);
    	for(int i = 0; i < result2.length; i++){
    		for(int j = 0; j < 2; j++){
    			System.out.print(result2[i][j] + " ");
    		}
    		System.out.println();
    	}
    }
}