import java.util.List;
import java.util.LinkedList;
import java.util.Stack;

class Solution345 {
    public String reverseVowels(String s) {
    	Stack<Character> stack = new Stack<>();
    	List<Integer> list = new LinkedList<>();
    	char[] arr = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    	char[] array = s.toCharArray();
   loop:for(int i = 0; i < array.length; i++){
    		for(char ele: arr){
    			if(ele == array[i]){
    				stack.push(array[i]);
    				list.add(i);
    				continue loop;
    			}
    		}
    	}
    	for(int index = 0; index < list.size(); index++){
    		array[list.get(index)] = stack.pop();
    	}
    	return String.valueOf(array);
    }
}