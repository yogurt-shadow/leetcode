/**
* Solution155
*/

class MinStack {
    int[] number;
    int[] min;
    int index;

    /** initialize your data structure here. */
    public MinStack() {
        number = new int[10000];
        min = new int[10000];
        index = 0;
    }
    
    public void push(int x) {
        number[index] = x;
        if(index == 0){
            min[0] = x;
        }
        else{
            min[index] = Math.min(min[index - 1], x);
        }
        index += 1;
    }
    
    public void pop() {
        index -= 1;

    }
    
    public int top() {
        return number[index - 1];
    }
    
    public int getMin() {
        return min[index - 1];
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */