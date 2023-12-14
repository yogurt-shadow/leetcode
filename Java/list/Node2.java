class Node2 {
    public int val;
    public Node2 prev;
    public Node2 next;
    public Node2 child;

    public Node2(int val, Node2 next, Node2 child){
    	this.val = val;
    	this.next = next;
    	this.child = child;
    }

    public Node2(int val){
        this.val = val;
    }
}