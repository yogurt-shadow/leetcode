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
class Solution21 {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
    	ListNode sentinel = new ListNode();
    	ListNode point1 = l1, point2 = l2;
    	ListNode point = sentinel;
    	while(l1 != null || l2 != null){
    		if(l1 == null){
    			point.next = new ListNode(l2.val);
    			l2 = l2.next;
    		}

    		else if(l2 == null){
    			point.next = new ListNode(l1.val);
    			l1 = l1.next;
    		}

    		else{
    			if(l1.val >= l2.val){
    				point.next = new ListNode(l2.val);
    				l2 = l2.next;
    			}

    			else{
    				point.next = new ListNode(l1.val);
    				l1 = l1.next;
    			}
    		}
    		point = point.next;
    	}
    	return sentinel.next;
    }
}