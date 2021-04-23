#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<stack>

using namespace std;
typedef long long ll;

/* Solution208 */
class Node{
public:
    char val;
    unordered_map<char, Node*> mp;
    bool have;

    Node(){
        val = ' ';
        have = false;
    }

    Node(char x){
        val = x;
        have = false;
    }
};

class Trie {
public:
    Node* root;
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* node = root;
        for(int i = 0; i < word.length(); i++){
            char cur = word[i];
            if(node -> mp.find(cur) == node -> mp.end()){
                node -> mp[cur] = new Node(cur);
            }
            node = node -> mp[cur];
        }
        node -> have = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* node = root;
        for(int i = 0; i < word.length(); i++){
            char cur = word[i];
            if(node -> mp.find(cur) == node -> mp.end()){
                return false;
            }
            node = node -> mp[cur];
        }
        return node -> have; 
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i = 0; i < prefix.length(); i++){
            char cur = prefix[i];
            if(node -> mp.find(cur) == node -> mp.end()){
                return false;
            }
            node = node -> mp[cur];
        }
        return node -> mp.size() || node -> have;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */