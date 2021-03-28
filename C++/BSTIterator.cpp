/**
 Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
#include<iostream>
#include<vector>

using namespace std;

class BSTIterator {
public:
    vector<int> vec;
    int index;
    int size;

    BSTIterator(TreeNode* root) {
        fill(vec, root);
        index = 0;
        size = vec.size();
    }

    void fill(vector<int>& vec, TreeNode* root){
        if(!root){
            return;
        }
        fill(vec, root -> left);
        vec.push_back(root -> val);
        fill(vec, root -> right);
    }
    
    int next() {
        return vec[index++];
    }
    
    bool hasNext() {
        return index < size;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */