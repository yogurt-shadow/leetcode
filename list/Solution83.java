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
class Solution83 {
    public ListNode deleteDuplicates(ListNode head) {
    	if(head == null || head.next == null){
    		return head;
    	}
    	ListNode point1 = head;
    	ListNode point2 = point1.next;
    	while(point1.next != null){
    		if(point1.val == point2.val){
    			point1.next = point2.next;
    			point2 = point2.next;
    		}
    		else{
    			point1 = point1.next;
    			point2 = point2.next;
    		}
    	}
    	return head;
    }
}