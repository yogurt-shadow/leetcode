/*
// Definition for a Node.
class Node {
    public int val;
    public Node prev;
    public Node next;
    public Node child;
};
*/

class Solution430 {
    public Node2 flatten(Node2 head) {
        if(head == null){
           return head;
       }
        Node2 result = new Node2(1);
        Node2 point  =result;
        add(point, head);
        result.next.prev = null;
        return result.next;
    }

    private Node2 add(Node2 result, Node2 head){
    	if(head == null){
    		return result;
    	}

    	result.next = new Node2(head.val);
        result.next.prev = result;
        result.next.child = null;
    	result = result.next;
    	result = add(result, head.child);
    	result = add(result, head.next);
    	return result;
    }

    public static void main(String[] args){
    	Solution430 s = new Solution430();
        Node2 ten = new Node2(10, null, null);
        Node2 nine = new Node2(9, ten, null);
        Node2 eight = new Node2(8, nine, null);
        Node2 seven = new Node2(7, eight, null);
        Node2 six = new Node2(6, null, null);
        Node2 five = new Node2(5, six, null);
        Node2 four = new Node2(4, five, null);
        Node2 three = new Node2(3, four, seven);
        Node2 two = new Node2(2, three, null);
        Node2 one = new Node2(1, two, null);
        Node2 result = s.flatten(one);

	}
}