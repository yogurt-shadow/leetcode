/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution86 {
    public ListNode partition(ListNode head, int x) {
    	ListNode small = new ListNode();
        ListNode large = new ListNode();
        ListNode point1 = small;
        ListNode point2 = large;

        while(head != null){
            if(head.val >= x){
                point2.next = head;
                point2 = point2.next;
            }

            else{
                point1.next = head;
                point1 = point1.next;
            }
            head = head.next;
        }

        point1.next = large.next;
        point2.next = null;
        return small.next;
    }

    public static void main(String[] args){
    	Solution86 s = new Solution86();


        ListNode test2 = new ListNode(1, new ListNode(2, new ListNode(3)));
        s.partition(test2, 4);
    }
}