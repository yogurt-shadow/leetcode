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
class Solution25 {
    public ListNode reverseKGroup(ListNode head, int k) {
        if(head == null){
        	return head;
        }
        if(k == 1){
          return head;
        }

      
        ListNode point1 = head;
        ListNode result = head;
        boolean changed = false;
        ListNode former = new ListNode();

      while(true){
      	if(point1 == null){
      		return result;
		}
       	  int index = k;
       	  ListNode point2 = point1;
       	while(index > 1){
       		point2 = point2.next;
       		index -= 1;
       		if(point2 == null){
       			return result;
       		}
       	}

       	ListNode[] pointers = new ListNode[k];
       	ListNode copy = point1;
       	int index2 = 0;
       	while(copy != point2.next){
       		pointers[index2] = copy;
       		index2 += 1;
       		copy = copy.next;
       	}

       	point1.next = copy;
       	for(int i = 1; i < k; i++){
       		pointers[i].next = pointers[i - 1];
       	}
        if(changed){
        former.next = pointers[k - 1];
      }
        if(!changed){
          result = point2;
        }
        former = point1;
        point1 = copy;
        changed = true;
       }
      
    }

    public static void main(String[] args){
    	Solution25 s = new Solution25();
    	ListNode test = new ListNode(1, new ListNode(2));
    	ListNode reverse1 = s.reverseKGroup(test, 2);
    }
}