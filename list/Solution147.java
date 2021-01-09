/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution147 {
    public ListNode insertionSortList(ListNode head) {
    	if(head == null || head.next == null){
    		return head;
    	}
    	ListNode temp = head.next;
    	ListNode next = insertionSortList(temp);
    	
    	head.next = null;
    	if(next.val >= head.val){
    		head.next = next;
    		return head;
    	}
    	ListNode point = next;
    	while(point.next != null && head.val > point.next.val){
    		point = point.next;
    	}
    	if(point.next == null){
    		point.next = head;
    		return next;
    	}

    	ListNode copy = point.next;
    	point.next = head;
    	head.next = copy;
    	return next;
    }

    public static void main(String[] args){
    	Solution147 s = new Solution147();
    	ListNode test = new ListNode(4, new ListNode(2, new ListNode(1, new ListNode(3))));
    	ListNode result = s.insertionSortList(test);
    	
    }
}