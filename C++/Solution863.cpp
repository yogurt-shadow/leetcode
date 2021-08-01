#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution863 {
public:
    unordered_map<TreeNode*, TreeNode*> father;

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        dfs(root, nullptr);
        explore(target, nullptr, k, ans);
        return ans;
    }

    void explore(TreeNode* target, TreeNode* pre, int k, vector<int>& ans){
        if(!target){
            return;
        }
        if(k == 0){
            ans.push_back(target -> val);
            return;
        }
        TreeNode* list[] = {father[target], target -> left, target -> right};
        for(int i = 0; i < 3; i++){
            if(list[i] != pre){
                explore(list[i], target, k - 1, ans);
            }
        }
    }

    void dfs(TreeNode* cur, TreeNode* pre){
        if(!cur){
            return;
        }
        father[cur] = pre;
        dfs(cur -> left, cur);
        dfs(cur -> right, cur);
    }
};