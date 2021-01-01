/**
* Solution225
*/
import java.util.Queue;
import java.util.LinkedList;

class MyStack {
    Queue<Integer> list1;
    Queue<Integer> list2;
    int index;
    /** Initialize your data structure here. */
    public MyStack() {
        list1 = new LinkedList<>();
        list2 = new LinkedList<>();
        index = 2;
    }
    
    /** Push element x onto stack. */
    public void push(int x) {
        if(index == 2){
            list2.offer(x);
            while(!list1.isEmpty()){
                list2.offer(list1.poll());
            }
            index = 1;
        }
        else{
            list1.offer(x);
            while(!list2.isEmpty()){
                list1.offer(list2.poll());
            }
            index = 2;
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    public int pop() {
        if(index == 1){
            return list2.poll();
        }
        else{
            return list1.poll();
        }
    }
    
    /** Get the top element. */
    public int top() {
       if(index == 1){
        return list2.peek();
       }

       else{
        return list1.peek();
       }
    }
    
    /** Returns whether the stack is empty. */
    public boolean empty() {
       if(index == 1){
        return list2.size() == 0;
       }

       else{
        return list1.size() == 0;
       }
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * boolean param_4 = obj.empty();
 */