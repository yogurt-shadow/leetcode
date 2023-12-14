import java.util.List;
import java.util.LinkedList;
import java.util.Map;
import java.util.HashMap;
import java.util.Queue;
import java.util.PriorityQueue;


class Solution1202 {
    public String smallestStringWithSwaps(String s, List<List<Integer>> pairs) {
    	UnionFind uf = new UnionFind(s.length());
    	for(List<Integer> pair: pairs){
    		uf.connect(pair.get(0), pair.get(1));
    	}
    	Map<Integer, Queue<Character>> map = new HashMap<>();
    	for(int i = 0; i < s.length(); i++){
    		int parent = uf.findparent(i);
    		if(!map.containsKey(parent)){
    			map.put(parent, new PriorityQueue<>());
    		}
    		map.get(parent).add(s.charAt(i));
    	}
    	StringBuilder str = new StringBuilder();
    	for(int i = 0; i < s.length(); i++){
    		int parent = uf.findparent(i);
    		char cur = map.get(parent).poll();
    		str.append(cur);
    	}
    	return str.toString();
    }
}