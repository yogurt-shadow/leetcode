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

class Solution897 {
public:
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> vec;
        dfs(vec, root);
        TreeNode* res = new TreeNode(vec[0]);
        TreeNode* copy = res;
        int index = 1;
        while(index < vec.size()){
            res -> right = new TreeNode();
            res = res -> right;
            res -> val = vec[index ++];
        }
        return copy;
    }

    void dfs(vector<int>& vec, TreeNode* root){
        if(!root) return;
        dfs(vec, root -> left);
        vec.push_back(root -> val);
        dfs(vec, root -> right);
    }
};