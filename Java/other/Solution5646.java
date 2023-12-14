import java.util.Map;
import java.util.HashMap;
import java.util.Set;
import java.util.HashSet;
import java.util.List;
import java.util.LinkedList;

class Solution5646 {
    public int minimumTeachings(int n, int[][] languages, int[][] friendships) {
    	Map<Integer, Set<Integer>> map = new HashMap<>();
    	for(int i = 1; i <= languages.length; i++){
    		map.put(i, new HashSet<>());
    		for(int ele: languages[i - 1]){
    			map.get(i).add(ele);
    		}
    	}
    	List<int[]> list = new LinkedList<>();
    	loop: for(int[] friends: friendships){
    		int a = friends[0];
    		int b = friends[1];
    		for(Integer ele: map.get(a)){
    			if(map.get(b).contains(ele)){
    				continue loop;
    			}
    		}
    		list.add(new int[]{a, b});
    	}
    	int min = Integer.MAX_VALUE;
    	for(int language = 1; language <= n; language++){
    		Set<Integer> set = new HashSet<>();
    		int number = 0;
    		for(int[] friend: list){
    			if(!map.get(friend[0]).contains(language) && !set.contains(friend[0])){
    				number += 1;
    				set.add(friend[0]);
    			}

    			if(!map.get(friend[1]).contains(language) && !set.contains(friend[1])){
    				number += 1;
    				set.add(friend[1]);
    			}
    		}
    		min = Math.min(min, number);
    	}
    	return min;
    }

    public static void main(String[] args){
    	Solution5646 s = new Solution5646();
    	int[][] test11 = new int[][]{new int[]{1}, new int[]{2}, new int[]{1, 2}};
    	int[][] test12 = new int[][]{new int[]{1, 2}, new int[]{1, 3}, new int[]{2, 3}};
    	System.out.println(s.minimumTeachings(2, test11, test12));
    }
}