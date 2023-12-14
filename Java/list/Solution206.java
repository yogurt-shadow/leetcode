/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution206 {
    public ListNode reverseList(ListNode head) {
    	if(head == null || head.next == null){
    		return head;
    	}

    	ListNode reverse = reverseList(head.next);
    	ListNode point = reverse;
    	while(point.next != null){
    		point = point.next;
    	}
    	point.next = new ListNode(head.val);
    	return reverse;
    }

}