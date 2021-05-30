#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <stack>

using namespace std;
typedef long long ll;

const int BIT = 30;

struct TrieNode{
    TrieNode* left;
    TrieNode* right;

    TrieNode(){
        left = nullptr;
        right = nullptr;
    }
};

class Trie{
public:
    TrieNode* root;

    void add(int num){
        TrieNode* cur = root;
        for(int k = BIT; k >= 0; k--){
            int digit = (1 << k) & num;
            if(digit){
                if(!cur -> right){
                    cur -> right = new TrieNode();
                }
                cur = cur -> right;
            }
            else{
                if(!cur -> left){
                    cur -> left = new TrieNode();
                }
                cur = cur -> left;
            }
        }
    }

    int match(int num){
        int ans = 0;
        TrieNode* cur = root;
        for(int k = BIT; k >= 0; k--){
            int digit = (1 << k) & num;
            if(digit){
                if(cur -> left){
                    ans = ans * 2 + 1;
                    cur = cur -> left;
                }
                else{
                    ans = ans * 2;
                    cur = cur -> right;
                }
            }
            else{
                if(cur -> right){
                    ans = ans * 2 + 1;
                    cur = cur -> right;
                }
                else{
                    ans = ans * 2;
                    cur = cur -> left;
                }
            }
        }
        return ans;
    }
};

class Solution421 {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        int ans = 0;

        for(auto ele: nums){
            trie.add(ele);
            ans = max(ans, trie.match(ele));
        }
        return ans;
    }
};