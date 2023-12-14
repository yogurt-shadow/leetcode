/**
* Solution707
*/

class MyLinkedList {
    private class ListNode{
        private int val;
        private ListNode prev;
        private ListNode next;

        public ListNode(int val, ListNode prev, ListNode next){
            this.val = val;
            this.prev = prev;
            this.next = next;
        }

        public ListNode(int val){
            this.val = val;
            prev = null;
            next = null;
        }
    }
    
    ListNode head;
    int size;
    /** Initialize your data structure here. */
    public MyLinkedList() {
        size = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    public int get(int index) {
        if(index < 0 || index >= size){
            return -1;
        }
        ListNode cur = head;
        while(index > 0){
            cur = cur.next;
            index -= 1;
        }
        return cur.val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    public void addAtHead(int val) {
        if(size == 0){
            head = new ListNode(val);
        }
        else{
            ListNode cur = new ListNode(val, null, head);
            head.prev = cur;
            head = cur;
        }
        size += 1;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    public void addAtTail(int val) {
        if(size == 0){
            head = new ListNode(val);
        }
        else{
            ListNode point = head;
            while(point.next != null){
                point = point.next;
            }
            ListNode tail = new ListNode(val, point, null);
            point.next = tail;
            
        }
        size += 1;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    public void addAtIndex(int index, int val) {
        if(index > size){
            return;
        }

        if(index <= 0){
            addAtHead(val);
        }

        else if(index == size){
            addAtTail(val);
        }

        else{
            ListNode cur = head;
            while(index > 1){
                cur = cur.next;
                index -= 1;
            }
            ListNode add = new ListNode(val, cur, cur.next);
            cur.next = add;
            size += 1;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    public void deleteAtIndex(int index) {
        if(index >= size || index < 0){
            return;
        }

        if(index == 0){
            head = head.next;
        }

        else{
            ListNode cur = head;
            while(index > 1){
                cur = cur.next;
                index -= 1;
            }
            cur.next = cur.next.next;
            if(cur.next != null) {
                cur.next.prev = cur;
            }
        }
        size -= 1;
    }

    public static void main(String[] args){
        MyLinkedList linkedList = new MyLinkedList();
        linkedList.addAtHead(5);
        linkedList.addAtIndex(1, 2);
        linkedList.get(1);
        linkedList.addAtHead(6);
        linkedList.addAtTail(2);
        linkedList.get(3);
        linkedList.addAtTail(1);
        linkedList.get(5);
    }
    /*
["MyLinkedList","addAtHead","addAtIndex","get","addAtHead","addAtTail","get","addAtTail","get","addAtHead","get","addAtHead"]
        [[],[5],[1,2],[1],[6],[2],[3],[1],[5],[2],[2],[6]]
        */

}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */