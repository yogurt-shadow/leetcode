import java.util.List;
import java.util.LinkedList;
import java.util.Set;
import java.util.HashSet;

class Solution207 {
	Set<Integer> this_turn = new HashSet<>();
	Set<Integer> visited = new HashSet<>();

    public boolean canFinish(int numCourses, int[][] prerequisites) {
    	List<List<Integer>> list = new LinkedList<>();
    	for(int i = 0; i < numCourses; i++){
    		list.add(new LinkedList<>());
    	}
    	for(int[] ele: prerequisites){
    		list.get(ele[0]).add(ele[1]);
    	}

    	for(int i = 0; i < numCourses; i++){
    		this_turn.clear();
    		if(dfs(i, list)){
    			return false;
    		}
    	}
    	return true;
    }

    private boolean dfs(int start, List<List<Integer>> list){
    	this_turn.add(start);
    	for(Integer neighbor: list.get(start)){
    		if(this_turn.contains(neighbor)){
    			return true;
    		}
    		if(!visited.contains(neighbor)){
    			if(dfs(neighbor, list)){
    				this_turn.remove(start);
    				return true;
    			}
    		}
    	}
		this_turn.remove(start);
    	visited.add(start);
    	return false;
    }

    public static void main(String[] args){
    	Solution207 s = new Solution207();
    	int[][] prerequisites1 = {{0, 1}, {0, 2}, {1, 2}};
    	System.out.println(s.canFinish(3, prerequisites1));
    }
}