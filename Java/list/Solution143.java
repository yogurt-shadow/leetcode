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
class Solution143 {
    public void reorderList(ListNode head) {
        if(head == null || head.next == null || head.next.next == null){
        	return;
        }

        ListNode point = head;
        while(point.next.next != null){
        	point = point.next;
        }
        ListNode temp = head.next;
        head.next = point.next;
        point.next = null;
        reorderList(temp);
        head.next.next = temp;
    }
}