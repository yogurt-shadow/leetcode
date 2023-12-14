package other;

public class ListNode{
	public int val;
	public ListNode next;

	public ListNode(int val){
		this.val = val;
	}

	public ListNode(int val, ListNode x){
		this.val = val;
		next = x;
	}
}