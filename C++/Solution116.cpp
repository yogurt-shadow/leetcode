#include<iostream>
#include<vector>

#include<unordered_map>

using namespace std;


class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution116 {
public:
    Node* connect(Node* root) {
        if(!root || !root -> left){
            return root;
        }
        connect2(root, root -> right);
        connect2(root, root -> left);
        return root;
    }

    void connect2(Node* root, Node* child){
        if(!child){
            return;
        }
        if(child == root -> left){
            child -> next = root -> right;
        }
        else{
            if(root -> next){
                child -> next = root -> next -> left;
            }
        }
        connect2(child, child -> right);
        connect2(child, child -> left);
    }
};