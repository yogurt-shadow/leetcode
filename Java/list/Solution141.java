/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution141 {
    public boolean hasCycle(ListNode head) {
        ListNode quick = head;
        ListNode slow = head;
        while(quick != null){
        	if(quick.next == null){
        		return false;
        	}
        	quick = quick.next.next;
        	slow = slow.next;
        	if(quick == slow){
        		return true;
        	}
        }
        return false;
    }
}