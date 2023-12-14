/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution234 {
    public boolean isPalindrome(ListNode head) {
    	if(head == null || head.next == null){
    		return true;
    	}
    	ListNode point = head;
    	while(point.next.next != null){
    		point = point.next;
    	}
    	if(point.next.val != head.val){
    		return false;
    	}
    	point.next = null;
    	return isPalindrome(head.next);

    }
}