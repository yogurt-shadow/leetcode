/**
* Solution211
*/
import java.util.List;
import java.util.LinkedList;
import java.util.Queue;

class WordDictionary {
	private class Node{
		private char alphabet;
		private boolean end;
		private List<Node> next;

		public Node(char alphabet, boolean end){
			this.alphabet = alphabet;
			this.end = end;
			next = new LinkedList<>();
		}
	}

	private class Trie{
		private Node start;

		public Trie() {
        	start = new Node(' ', false);
    	}


    	public void insert(String word) {
        int index = 0;
        Node node = start;
   loop:  while(index < word.length()){
            char cur = word.charAt(index);
            for(Node node2: node.next){
                if(node2.alphabet == cur){
                    node = node2;
                    index += 1;
                    continue loop;
                }
        }
        break;
    }
        if(index == word.length()){
            node.end = true;
        }
        else{
            while(index < word.length()){
                Node next_node = new Node(word.charAt(index), false);
                node.next.add(next_node);
                node = next_node;
                index += 1;
            }
            node.end = true;
        }
    }
    
    /** Returns if the word is in the trie. */
    public boolean search(String word) {
        Node node = start;
        int index = 0;
loop:  while(index < word.length()){
            char cur = word.charAt(index);
            for(Node node2: node.next){
                if(node2.alphabet == cur){
                    index += 1;
                    node = node2;
                    continue loop;
                }
            }
            return false;
        }
        return node.end;
    }
	}

	private Trie trie;
    /** Initialize your data structure here. */
    public WordDictionary() {
    	trie = new Trie();
    }
    
    public void addWord(String word) {
    	trie.insert(word);
    }
    
    public boolean search(String word) {
    	if(!word.contains(".")){
    		return trie.search(word);
    	}
        Queue<Node> queue = new LinkedList<>();
        for(Node node: trie.start.next){
            queue.add(node);
        }

        int index = 0;
     loop: while(index < word.length()){

            int size = queue.size();
            char cur = word.charAt(index);
            if(size == 0){
                return false;
            }
            if(index == word.length() - 1){
                if(cur == '.'){
                    for(Node node: queue){
                        if(node.end){
                            return true;
                        }
                    }
                    return false;
                }
                for(Node node: queue){
                    if(node.alphabet == cur && node.end){
                        return true;
                    }
                }
                return false;
            }

            if(cur == '.'){
                for(int i = 0; i < size; i++){
                    Node node = queue.poll();
                    for(Node next_node: node.next){
                        queue.add(next_node);
                    }
                }
                index += 1;
                continue loop;
            }
            else{
                for(int i = 0; i < size; i++){
                    Node node = queue.poll();
                    if(node.alphabet == cur){
                        for(Node next_node: node.next){
                            queue.add(next_node);
                        }

                    }
                }
                index += 1;
                if(queue.size() == 0){
                    return false;
                }
            }
        }
        return true;
    }

    public static void main(String[] args){
        WordDictionary word = new WordDictionary();
        word.addWord("dad");
        word.addWord("mad");
       word.addWord("bad");
        System.out.println(word.search(".ad"));
        System.out.println(word.search("b.."));
    }
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * boolean param_2 = obj.search(word);
 */