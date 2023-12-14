/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution328 {
    public ListNode oddEvenList(ListNode head) {
        ListNode odd = new ListNode(1);
        ListNode even = new ListNode(1);
        boolean is_odd = true;
        ListNode point = head;
        ListNode point1 = odd;
        ListNode point2 = even;
        while(point != null){
        	if(is_odd){
        		point1.next = point;
        		point1 = point1.next;
        	}
        	else{
        		point2.next = point;
        		point2 = point2.next;
        	}
        	is_odd = !is_odd;
        	point = point.next;
        }
        point1.next = even.next;
        point2.next = null;
        return odd.next;
    }
}