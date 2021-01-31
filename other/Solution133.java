/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;
    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
*/
import java.util.*;

class Solution133 {
    private class Node{
        public int val;
        public List<Node> neighbors;
        public Node() {
            val = 0;
            neighbors = new ArrayList<Node>();
        }
        public Node(int _val) {
            val = _val;
            neighbors = new ArrayList<Node>();
        }
        public Node(int _val, ArrayList<Node> _neighbors) {
            val = _val;
            neighbors = _neighbors;
        }
    }

    public Node cloneGraph(Node node) {
       if(node == null){
            return null;
       }
       if(node.neighbors.size() == 0){
            Node newone = new Node(node.val, new ArrayList<>());
            return newone;
       }
       Map<Integer, List<Integer>> map = new HashMap<>();
       Queue<Node> queue = new LinkedList<>();
       Set<Integer> visited = new HashSet<>();
       queue.add(node);
       visited.add(node.val);
       while(queue.size() > 0){
            Node cur = queue.poll();
            int value = cur.val;
            if(!map.containsKey(value)){
                map.put(value, new LinkedList<>());
            }
            for(Node neighbor: cur.neighbors){
                map.get(value).add(neighbor.val);
                if(!visited.contains(neighbor.val)){
                    visited.add(neighbor.val);
                    queue.add(neighbor);
                }
            }
       }
       Map<Integer, Node> index = new HashMap<>();
       for(Integer ele: map.keySet()){
            index.put(ele, new Node(ele, new ArrayList<>()));
       }
       for(Integer ele: index.keySet()){
            List<Node> list = index.get(ele).neighbors;
            for(Integer ele2: map.get(ele)){
                list.add(index.get(ele2));
            }
       }
       return index.get(node.val);
    }
}