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

class Solution872 {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        auto vec1 = leaves(root1);
        auto vec2 = leaves(root2);
        if(vec1.size() != vec2.size()){
            return false;
        }
        for(int i = 0; i < vec1.size(); i++){
            if(vec1[i] != vec2[i]){
                return false;
            }
        }
        return true;
    }

    vector<int> leaves(TreeNode* root){
        vector<int> res;
        put(res, root);
        return res;
    }

    void put(vector<int>& res, TreeNode* root){
        if(!root){
            return;
        }
        if(!root->left && !root->right){
            res.push_back(root->val);
            return;
        }
        put(res, root->left);
        put(res, root->right);
    }
};