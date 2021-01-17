import java.util.Stack;

class Solution316 {
    public String removeDuplicateLetters(String s) {
    	int[] freq = new int[26];
    	for(int i = 0; i < s.length(); i++){
    		char cur = s.charAt(i);
    		freq[cur - 'a'] += 1;
    	}
    	Stack<Character> stack = new Stack<>();
    	boolean[] instack = new boolean[26];
    	for(int i = 0; i < 26; i++){
    		instack[i] = false;
    	}

    	for(int i = 0; i < s.length(); i++){
    		char cur = s.charAt(i);
            freq[cur - 'a'] -= 1;
    		if(instack[cur - 'a']){
    			continue;
    		}
    		while(!stack.empty() && freq[stack.peek() - 'a'] > 0 && stack.peek() > cur){
    			instack[stack.pop() - 'a'] = false;
    		}
    		stack.push(cur);
    		instack[cur - 'a'] = true;
    	}
    	StringBuilder str = new StringBuilder();
    	while(!stack.empty()){
    		str.append(stack.pop());
    	}
    	return str.reverse().toString();
    }

    public static void main(String[] args){
    	Solution316 s = new Solution316();
    	System.out.println(s.removeDuplicateLetters("bbcaac"));
    }
}