#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution156 {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if(!root || !root -> left){
            return root;
        }
        TreeNode* l_copy = root -> left;
        TreeNode* r_copy = root -> right;
        root -> left = nullptr;
        root -> right = nullptr;
        TreeNode *newroot = upsideDownBinaryTree(l_copy);
        l_copy -> left = r_copy;
        l_copy -> right = root;
        return newroot;
    }
};