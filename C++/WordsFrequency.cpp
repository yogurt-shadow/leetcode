#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <stack>
using namespace std;

class Trie {
public:
    int num;
    Trie* next[26];

    Trie(){
        num = 0;
        for(int i = 0; i < 26; i++){
            next[i] = nullptr;
        }
    }
};

class WordsFrequency {
public:
    Trie* root;

    void insert(string str){
        Trie* cur = root;
        for(int index = 0; index < str.length(); index ++){
            char x = str[index];
            if(!cur -> next[x - 'a']){
                cur -> next[x - 'a'] = new Trie();
            }
            cur = cur -> next[x - 'a'];
        }
        cur -> num ++;
    }

    WordsFrequency(vector<string>& book) {
        root = new Trie();
        for(auto ele: book){
            insert(ele);
        }
    }
    
    int get(string word) {
        Trie* cur = root;
        for(int index = 0; index < word.length(); index++){
            char x = word[index];
            if(!cur -> next[x - 'a']){
                return 0;
            }
            cur = cur -> next[x - 'a'];
        }
        return cur -> num;
    }
};

/**
 * Your WordsFrequency object will be instantiated and called as such:
 * WordsFrequency* obj = new WordsFrequency(book);
 * int param_1 = obj->get(word);
 */