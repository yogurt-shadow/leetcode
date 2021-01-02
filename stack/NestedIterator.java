/**
*  Solution341
*/
import java.util.Iterator;
import java.util.List;
import java.util.LinkedList;

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * public interface NestedInteger {
 *
 *     // @return true if this NestedInteger holds a single integer, rather than a nested list.
 *     public boolean isInteger();
 *
 *     // @return the single integer that this NestedInteger holds, if it holds a single integer
 *     // Return null if this NestedInteger holds a nested list
 *     public Integer getInteger();
 *
 *     // @return the nested list that this NestedInteger holds, if it holds a nested list
 *     // Return null if this NestedInteger holds a single integer
 *     public List<NestedInteger> getList();
 * }
 */

/**
public class NestedIterator implements Iterator<Integer> {
	private List<Integer> list;
	private int index;
    public NestedIterator(List<NestedInteger> nestedList) {
        list = new LinkedList<>();
        index = 0;
        for(NestedInteger ele: nestedList){
        	add(ele);
        }
    }

    private void add(NestedInteger x){
    	if(x.isInteger()){
    		list.add(x.getInteger());
    	}

    	else{
    		List<NestedInteger> l = x.getList();
    		for(NestedInteger xxx: l){
    			add(xxx);
    		}
    	}
    }

    @Override
    public Integer next() {
    	index += 1;
        return list.get(index - 1);
    }

    @Override
    public boolean hasNext() {
        return index < list.size();
    }
}

*/

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i = new NestedIterator(nestedList);
 * while (i.hasNext()) v[f()] = i.next();
 */