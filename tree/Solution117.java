package  tree;


/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}
    
    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

class Solution117 {
    public Node connect(Node root) {
        if(root == null || (root.left == null && root.right == null)){
            return root;
        }

        if(root.left != null && root.right != null){
            root.left.next = root.right;
        }

        if(root.next != null){
            if(root.right != null){
            level_connect(root, root.right, root.next);
        }
            else{
                level_connect(root, root.left, root.next);
            }
        }
       

        connect(root.right);
        connect(root.left);
        /**
        *  connect right first !!!
           eg.          2
                       / \
                      1   3
                     / \  / \
                    0  7 9   1
                   /  /\    / \
                  2  1  0   8  8

            if connect left first, then 9 doesn't have next, because you haven't connected right
            then, 0 (the leaf) won't be connected to 8 (the left leaf), because 7 -> 9 -> null 
        */
        return root;
    }

    private void level_connect(Node root, Node child, Node next){
        if(next.next == null && next.left == null && next.right == null){
            return;
        }

        if(next.left != null){
            child.next = next.left;
        }

        else if(next.right != null){
            child.next = next.right;
        }

        else{
            level_connect(root, child, next.next);
        }
    }

    public static void main(String[] args){
        Solution117 s = new Solution117();
        Node root = new Node(1, new Node(2, new Node(4), new Node(5), null), new Node(3, null, new Node(7), null), null);
        root = s.connect(root);
        System.out.println(root.left.next.val);
    }
}