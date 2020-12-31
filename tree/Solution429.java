package tree;
import java.util.List;
import java.util.LinkedList;

/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution429 {
    public List<List<Integer>> levelOrder(Node2 root) {
        List<List<Integer>> result = new LinkedList<>();

        add(result, root, 1);
        return result;
    }

    private void add(List<List<Integer>> list, Node2 root, int level){
        if(root == null){
            return;
        }

        if(list.size() < level){
            list.add(new LinkedList<Integer>());
        }

        list.get(level - 1).add(root.val);
        if(root.children != null){
        for(Node2 child: root.children){
            add(list, child, level + 1);
        }
    }
    }

    public static void main(String[] args){
        List<Node2> child1 = new LinkedList<>();
        child1.add(new Node2(5));
        child1.add(new Node2(6));
        List<Node2> child2 = new LinkedList<>();
        child2.add(new Node2(3, child1));
        child2.add(new Node2(2));
        child2.add(new Node2(4));
        Node2 root = new Node2(1, child2);

        Solution429 s = new Solution429();
        List<List<Integer>> x = s.levelOrder(root);
        for(List<Integer> ele: x){
            for(Integer aaa: ele){
                System.out.print(aaa + " ");
            }
            System.out.println();
        }
    }
}