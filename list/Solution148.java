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
class Solution148 {
    public ListNode sortList(ListNode head) {
    	if(head == null || head.next == null){
    		return head;
    	}
    	int size = size(head);
    	int index = size / 2;
    	ListNode point = head;
    	while(index > 1){
    		point = point.next;
    		index -= 1;
    	}
    	ListNode right = point.next;
    	point.next = null;
    	ListNode left = sortList(head);
    	right = sortList(right);
    	return merge(left, right);
    }

    private ListNode merge(ListNode list1, ListNode list2){
    	ListNode point1 = list1;
    	ListNode point2 = list2;
    	ListNode sentinel = new ListNode(1);
    	ListNode point = sentinel;
    	while(point1 != null || point2 != null){
    		if(point1 == null){
    			point.next = point2;
    			point2 = point2.next;
    			point = point.next;
    		}

    		else if(point2 == null){
    			point.next = point1;
    			point1 = point1.next;
    			point = point.next;
    		}

    		else{
    			if(point1.val > point2.val){
    				point.next = point2;
    				point2 = point2.next;
    			}
    			else{
    				point.next = point1;
    				point1 = point1.next;
    			}
    			point = point.next;
    		}
    	}
    	return sentinel.next;
    }

    private int size(ListNode head){
    	ListNode point = head;
    	int result = 0;
    	while(point != null){
    		point = point.next;
    		result += 1;
    	}
    	return result;
    }

    public static void main(String[] args){
    	Solution148 s = new Solution148();
    	ListNode test = new ListNode(4, new ListNode(2, new ListNode(1, new ListNode(3))));
    	ListNode result = s.sortList(test);
    }
}