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
class Solution61 {
    public ListNode rotateRight(ListNode head, int k) {
    	if(head == null || head.next == null || k == 0){
    		return head;
    	}
    	int size = size(head);
    	for(int i = 0; i < k % size; i++){
    		head = rotateonce(head);
    	}
    	return head;
    }

    private ListNode rotateonce(ListNode head){
    	ListNode point = head;
    	while(point.next.next != null){
    		point = point.next;
    	}
    	point.next.next = head;
    	ListNode result = point.next;
    	point.next = null;
    	return result;
    }

    private int size(ListNode head){
    	ListNode point = head;
    	int size = 0;
    	while(point != null){
    		size += 1;
    		point = point.next;
    	}
    	return size;
    }
}