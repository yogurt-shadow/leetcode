/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution138 {
    public Node copyRandomList(Node head) {
        Node sentinel = new Node(1);
        Node point1 = head;
        Node point2 = sentinel;
        while(point1 != null){
            point2.next = new Node(point1.val);
            point1 = point1.next;
            point2 = point2.next;
        }

        point1 = head;
        point2 = sentinel.next;

        while(point1 != null){
            if(point1.random == null){
                point2.random = null;
            }
            else{
                Node point3 = head;
                int index = 0;
                while(point1.random != point3){
                    point3 = point3.next;
                    index += 1;
                }
                Node point4 = sentinel.next;
                while(index > 0){
                    point4 = point4.next;
                    index -= 1;
                }
                point2.random = point4;
            }
            point1 = point1.next;
            point2 = point2.next;
        }

        return sentinel.next;
    }

}