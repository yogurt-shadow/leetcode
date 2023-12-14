// Java Iterator interface reference:
// https://docs.oracle.com/javase/8/docs/api/java/util/Iterator.html
import java.util.Queue;
import java.util.LinkedList;
import java.util.Iterator;

class PeekingIterator implements Iterator<Integer> {
	Queue<Integer> queue;
	public PeekingIterator(Iterator<Integer> iterator) {
	    // initialize any member here.
		queue = new LinkedList<>();
		for (Iterator<Integer> it = iterator; it.hasNext(); ) {
			Integer ele = it.next();
			queue.add(ele);
		}
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	public Integer peek() {
        return queue.peek();
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	@Override
	public Integer next() {
	    return queue.poll();
	}
	
	@Override
	public boolean hasNext() {
	    return queue.size() > 0;
	}
}