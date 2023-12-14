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
class Solution19 {
    public ListNode removeNthFromEnd(ListNode head, int n) {
    	if(head == null || head.next == null){
    		return null;
    	}
      ListNode sentinel = new ListNode(1);
      sentinel.next = head;
      while(sentinel.next != null){
      	ListNode cur = sentinel.next;
      	int index = n;
      	while(index > 0){
      		cur = cur.next;
      		index -= 1;
      	}
      	if(cur == null){
      		if(sentinel.next == head) {
				sentinel.next = sentinel.next.next;
				return sentinel.next;
			}
      		else{
      			sentinel.next = sentinel.next.next;
      			return head;
			}

      	}
      	sentinel = sentinel.next;
      }
      return null;
    }

    public static void main(String[] args){
    	Solution19 s = new Solution19();
    	ListNode test = new ListNode(1);
    	ListNode next = new ListNode(2);
    	test.next = next;
    	ListNode result = s.removeNthFromEnd(test, 2);
    }
}