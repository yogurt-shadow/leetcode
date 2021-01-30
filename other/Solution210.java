import java.util.Set;
import java.util.HashSet;
import java.util.List;
import java.util.LinkedList;
import java.util.Arrays;
import java.util.Map;
import java.util.HashMap;

class Solution210 {
	private int index;
	private Set<Integer> visited;
	private Set<Integer> turn;
	private int[] pre;
	private int[] post;
    
    public int[] findOrder(int numCourses, int[][] prerequisites) {
    	visited = new HashSet<>();
    	turn = new HashSet<>();
    	index = 0;
    	pre = new int[numCourses];
    	post = new int[numCourses];
    	List<List<Integer>> list = new LinkedList<>();
    	for(int i = 0; i < numCourses; i++){
    		list.add(new LinkedList<>());
    	}
    	for(int[] ele: prerequisites){
    		list.get(ele[1]).add(ele[0]);
    	}
    	for(int i = 0; i < numCourses; i++){
    		turn.clear();
    		if(!visited.contains(i)){
    			if(!dfs(i, list)){
    				return new int[0];
    			}
    		}
    	}
    	int[] result = new int[numCourses];
    	Map<Integer, Integer> map = new HashMap<>();
    	for(int i = 0; i < numCourses; i++){
    		map.put(post[i], i);
    	}
    	Arrays.sort(post);
    	for(int i = numCourses - 1; i >= 0; i--){
    		result[numCourses - 1 - i] = map.get(post[i]);
    	}
    	return result;
    }

    private boolean dfs(int start, List<List<Integer>> list){
    	pre[start] = index;
    	index += 1;
    	turn.add(start);
    	for(Integer neighbor: list.get(start)){
    		if(turn.contains(neighbor)){
    			return false;
    		}
    		if(!visited.contains(neighbor)){
    			if(!dfs(neighbor, list)){
    				return false;
    			}
    		}
    	}
    	turn.remove(start);
    	post[start] = index;
    	index += 1;
    	visited.add(start);
    	return true;
    }

    public static void main(String[] args){
    	Solution210 s = new Solution210();
    	int[][] test = {{1, 0}, {2, 1}, {0, 2}};
    	int[] result = s.findOrder(3, test);
    }
}