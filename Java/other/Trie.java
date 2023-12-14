/**
* Solution208
*/
import java.util.List;
import java.util.LinkedList;


class Trie {
    private class Node{
        private char alphabet;
        private List<Node> next;
        private boolean end;

        public Node(char cur, boolean end){
            alphabet = cur;
            this.end = end;
            next = new LinkedList<>();
        }
    }

    private Node start;
    /** Initialize your data structure here. */
    public Trie() {
        start = new Node(' ', false);
    }
    
    /** Inserts a word into the trie. */
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
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    public boolean startsWith(String prefix) {
        int index = 0;
        Node node = start;
        loop: while(index < prefix.length()){
            char cur = prefix.charAt(index);
            for(Node node2: node.next){
                if(node2.alphabet == cur){
                    node = node2;
                    index += 1;
                    continue loop;
                }
            }
            return false;
        }
        return node.end || node.next.size() > 0;
    }

    public static void main(String[] args){
        Trie trie = new Trie();
        trie.insert("apple");
        System.out.println(trie.search("apple"));   // 返回 true
        System.out.println(trie.search("app"));     // 返回 false
        System.out.println(trie.startsWith("app")); // 返回 true
        trie.insert("app"); 
        System.out.println(trie.search("app"));     // 返回 true

    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */