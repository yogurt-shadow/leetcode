/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution203 {
    public ListNode removeElements(ListNode head, int val) {
    	ListNode copy = new ListNode(1);
    	copy.next = head;
    	ListNode cur = copy;
    	while(cur.next != null){
    		if(cur.next.val == val){
    			cur.next = cur.next.next;
    		}
    		else{
    			cur = cur.next;
    		}
    	}
    	return copy.next;
    }

}