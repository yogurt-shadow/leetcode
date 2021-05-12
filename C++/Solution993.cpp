#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<stack>

using namespace std;
typedef long long ll;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution993 {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        auto node1 = find(0, root, x);
        auto node2 = find(0, root, y);
        return node1.first == node2.first && node1.second != node2.second;
    }

    pair<int, TreeNode*> find(int degree, TreeNode* root, int value){
        if(!root){
            return {degree, nullptr};
        }
        if(root -> left){
            if(root -> left -> val == value){
                return {degree + 1, root};
            }
            auto ele = find(degree + 1, root -> left, value);
            if(ele.second){
                return ele;
            }
        }
        if(root -> right){
            if(root -> right -> val == value){
                return {degree + 1, root};
            }
            auto ele = find(degree + 1, root -> right, value);
            if(ele.second){
                return ele;
            }
        }
        return {degree, nullptr};
    }
};