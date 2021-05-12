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

class Solution938 {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root){
            return 0;
        }        
        if(high < root-> val){
            return rangeSumBST(root->left, low, high);
        }
        if(low > root->val){
            return rangeSumBST(root->right, low, high);
        }
        return root->val + rangeSumBST(root->left, low, root->val) + rangeSumBST(root->right, root->val, high);
    }
};