/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * public interface NestedInteger {
 *     // Constructor initializes an empty nested list.
 *     public NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     public NestedInteger(int value);
 *
 *     // @return true if this NestedInteger holds a single integer, rather than a nested list.
 *     public boolean isInteger();
 *
 *     // @return the single integer that this NestedInteger holds, if it holds a single integer
 *     // Return null if this NestedInteger holds a nested list
 *     public Integer getInteger();
 *
 *     // Set this NestedInteger to hold a single integer.
 *     public void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     public void add(NestedInteger ni);
 *
 *     // @return the nested list that this NestedInteger holds, if it holds a nested list
 *     // Return null if this NestedInteger holds a single integer
 *     public List<NestedInteger> getList();
 * }
 */

/**
class Solution385 {
    public NestedInteger deserialize(String s) {
    	if(s.length() == 0){
    		return new NestedInteger();
    	}
    	if(s.charAt(0) != '['){
    		return new NestedInteger(Integer.parseInt(s));
    	}

/**
    	NestedInteger result = new NestedInteger();
    	result.add(new NestedInteger(123));
    	NestedInteger x = new NestedInteger();
    	x.add(new NestedInteger(456));
    	NestedInteger y = new NestedInteger();
    	y.add(new NestedInteger(789));
    	x.add(y);
    	result.add(x);
    	return result;
    	*/
    	/**
    	NestedInteger result = new NestedInteger();
    	int number = 0;
    	boolean negative = false;
    	boolean num = false;
    	for(int i = 1; i < s.length() - 1; i++){
    		char cur = s.charAt(i);
    		if(cur >= '0' && cur <= '9'){
    			num = true;
    			number = 10 * number + cur - '0';
    			if(i == s.length() - 2){
    				if(negative){
    					result.add(new NestedInteger(-number));
    					num = false;
    					negative = false;
    					number = 0;
    				}
    				else{
    				result.add(new NestedInteger(number));
    				number = 0;
    				num = false;
    			}
    			}
    		}
    		else if(cur == ','){
    			if(num){
    			if(negative){
    					result.add(new NestedInteger(-number));
    					negative = false;
    					num = false;
    					number = 0;
    				}
    				else{
    				result.add(new NestedInteger(number));
    				number = 0;
    				num = false;
    			}
    		}
    		
    		}

    		else if(cur == '['){
    			int partner = find(s, i);
    			NestedInteger part = deserialize(s.substring(i, partner + 1));
    			result.add(part);
    			i = partner;
    		}

    		else if(cur == '-'){
    			negative = true;
    		}
    	}
    	return result;

    }

    private int find(String s, int start){
    	int level = 1;
    	for(int i = start + 1; i < s.length(); i++){
    		char cur = s.charAt(i);
    		if(cur == '['){
    			level += 1;
    		}

    		if(cur == ']'){
    			level -= 1;
    			if(level == 0){
    				return i;
    			}
    		}
    	}
    	return -1;
    }
}
*/