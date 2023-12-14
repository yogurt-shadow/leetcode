import java.util.Set;
import java.util.HashSet;

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
public class Solution142 {
    public ListNode detectCycle(ListNode head) {
    	if(head == null){
    		return null;
    	}
        Set<ListNode> visited = new HashSet<>();
        ListNode point = head;
        while(point.next != null){
        	if(visited.contains(point)){
        		return point;
        	}
        	visited.add(point);
        	point = point.next;
        }
        return null;
    }

}