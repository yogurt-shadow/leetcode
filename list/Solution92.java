/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution92 {
    public ListNode reverseBetween(ListNode head, int m, int n) {
    	ListNode sentinel = new ListNode();
    	sentinel.next = head;
    	int length = n - m + 1;
    	ListNode point1 = sentinel;
    	while(m > 1){
    		point1 = point1.next;
    		m -= 1;
    	}
    	ListNode point2 = point1.next;
    	ListNode[] pointers = new ListNode[length];
    	int index = 0;
    	while(index < length){
    		pointers[index] = point2;
    		point2 = point2.next;
    		index += 1;
    	}
    	pointers[0].next = point2;
    	for(int i = 1; i < length; i++){
    		pointers[i].next = pointers[i - 1];
    	}
    	point1.next = pointers[length - 1];
    	return sentinel.next;
    }

    public static void main(String[] args){
    	Solution92 s = new Solution92();
    	ListNode test = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    	ListNode result = s.reverseBetween(test,2, 4);
    }
}