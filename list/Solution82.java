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
class Solution82 {
    public ListNode deleteDuplicates(ListNode head) {
    	ListNode sentinel = new ListNode();
    	sentinel.next = head;
    	ListNode point1 = sentinel;
    	ListNode point2 = head;
    	while(point1.next != null){
    		int value = point2.val;
    		if(point2.next != null && point2.next.val == value){
    			while(point2 != null && point2.val == value){
    				point2 = point2.next;
    			}
    			point1.next = point2;
    		}
    		else{
    			point1 = point1.next;
    			point2 = point1.next;
    		}
    	}
    	return sentinel.next;
    }

    public static void main(String[] args){
    	Solution82 s = new Solution82();
    	ListNode test = new ListNode(1, new ListNode(1, new ListNode(2, new ListNode(5))));
    	s.deleteDuplicates(test);
    }
}