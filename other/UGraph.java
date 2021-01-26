import java.util.List;
import java.util.LinkedList;
import java.util.Map;
import java.util.HashMap;
import java.util.Set;
import java.util.HashSet;

public class UGraph{
	private int n;
	private List<Set<Integer>> neighbor;
	private Set<Integer> set;

	public UGraph(int n){
		this.n = n;
		neighbor = new LinkedList<>();
		for(int i = 0; i < n; i++){
			neighbor.add(new HashSet<>());
		}
		set = new HashSet<>();
	}

	public void connect(int x, int y){
		if(!neighbor.get(x).contains(y)){
			neighbor.get(x).add(y);
		}
		if(!neighbor.get(y).contains(x)){
			neighbor.get(y).add(x);
		}
	}

	public boolean has_edge(int x, int y){
		return neighbor.get(x).contains(y);
	}

	public void dis_edge(int x, int y){
		if(!has_edge(x, y)){
			return;
		}
		neighbor.get(x).remove(y);
		neighbor.get(y).remove(x);
	}

	public boolean is_connected(int x, int y){
		set.clear();
		boolean result = is_connected2(x, y);
		set.clear();
		return result;
	}

	private boolean is_connected2(int x, int y){
		set.add(x);
		if(neighbor.get(x).contains(y)){
			return true;
		}
		for(Integer ele: neighbor.get(x)){
			if(set.contains(ele)){
				continue;
			}
			if(is_connected2(ele, y)){
				return true;
			}
		}
		return false;
	}

	private boolean dfs(int cur, int last){
		set.add(cur);
		for(Integer ele: neighbor.get(cur)){
			if(ele == last){
				continue;
			}
			if(set.contains(ele)){
				return true;
			}
			if(dfs(ele, cur)){
				return true;
			}
		}
		return false;
	}

	public boolean is_full_connected(){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < i; j++){
				if(!is_connected(i, j)){
					return false;
				}
			}
		}
		return true;
	}

	public boolean hasCycle(){
		set.clear();
		for(int i = 0; i < n; i++){
			set.clear();
			if(dfs(i, -1)){
				set.clear();
				return true;
			}
		}
		set.clear();
		return false;
	}
}