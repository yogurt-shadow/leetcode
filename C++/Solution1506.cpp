#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<map>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution1506 {
public:
    unordered_set<int> st;

    Node* findRoot(vector<Node*> tree) {
        for(auto node: tree){
            for(auto child: node -> children){
                dfs(child);
            }
        }
        for(auto node: tree){
            if(st.count(node -> val) == 0){
                return node;
            }
        }  
        return nullptr;
    }

    void dfs(Node* node){
        if(st.count(node -> val)){
            return;
        }
        st.insert(node -> val);
        for(auto child: node -> children){
            dfs(child);
        }
    }
};