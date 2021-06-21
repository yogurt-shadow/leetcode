#include <iostream>
#include <vector>

#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

struct TreeNode {
int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution337 {
public:
    unordered_map<TreeNode*, int> f, g;

    void dfs(TreeNode* root){
        if(!root){
            return;
        }
        dfs(root -> left);
        dfs(root -> right);
        f[root] = root -> val + g[root -> left] + g[root -> right];
        g[root] = max(f[root -> left], g[root -> left]) + max(f[root -> right], g[root -> right]);
    }

    int rob(TreeNode* root) {
        dfs(root);
        return max(f[root], g[root]);
    }
};