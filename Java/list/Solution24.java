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
class Solution24 {
    public ListNode swapPairs(ListNode head) {
    	if(head == null || head.next == null){
    		return head;
    	}

    	int temp = head.val;
    	head.val = head.next.val;
    	head.next.val = temp;
    	head.next.next = swapPairs(head.next.next);
    	return head;
    }
}