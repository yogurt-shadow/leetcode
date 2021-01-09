/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution160 {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode point = headA;
        while(point != null){
        	ListNode point2 = headB;
        	while(point2 != null){
        		if(point2 == point){
        			return point;
        		}
        		point2 = point2.next;
        	}
        	point = point.next;
        }
        return null;
    }
}