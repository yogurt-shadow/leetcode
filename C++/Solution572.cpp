#include<iostream>
#include<vector>


using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution572 {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(isequal(s, t)){
            return true;
        }
        if(!s){
            return false;
        }
        return isSubtree(s -> left, t) || isSubtree(s -> right, t);
    }

    bool isequal(TreeNode* tree1, TreeNode* tree2){
        if(!tree1 && !tree2){
            return true;
        }
        if(!tree1 || !tree2){
            return false;
        }
        if(tree1 -> val != tree2 -> val){
            return false;
        }
        return isequal(tree1 -> left, tree2 -> left) && isequal(tree1 -> right, tree2 -> right);
    }
};