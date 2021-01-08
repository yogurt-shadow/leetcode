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
class Solution23 {
    public ListNode mergeKLists(ListNode[] lists) {
        ListNode sentinel = new ListNode();
        int n = lists.length;
        ListNode[] pointers = new ListNode[n];
        for(int i = 0; i < n; i++){
        	pointers[i] = lists[i];
        }

        ListNode point = sentinel;
        while(!all_null(pointers)){
        	int min_index = min(pointers);
        	point.next = new ListNode(pointers[min_index].val);
        	pointers[min_index] = pointers[min_index].next;
        	point = point.next;
        }
        return sentinel.next;
    }

    private boolean all_null(ListNode[] pointers){
    	for(int i = 0; i < pointers.length; i++){
    		if(pointers[i] != null){
    			return false;
    		}
    	}
    	return true;
    }

    private int min(ListNode[] pointers){
    	int min = Integer.MAX_VALUE;
    	int index = 100;
    	for(int i = 0; i < pointers.length; i++){
    		if(pointers[i] == null){
    			continue;
    		}
    		if(pointers[i].val < min){
    			min = pointers[i].val;
    			index = i;
    		}
    	}
    	return index;
    }

    public static void main(String[] args){
    	Solution23 s = new Solution23();
    	ListNode list1 = new ListNode(1, new ListNode(4, new ListNode(5)));
    	ListNode list2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    	ListNode list3 = new ListNode(2, new ListNode(6));
    	ListNode[] test = new ListNode[]{list1, list2, list3};
    	ListNode result = s.mergeKLists(test);
    }
}