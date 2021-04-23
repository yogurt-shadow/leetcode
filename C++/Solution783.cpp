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

class Solution783 {
public:
    int minDiffInBST(TreeNode* root) {
        vector<int> vec;
        fill(vec, root);
        int ans = INT_MAX;
        for(int i = 0; i < vec.size() - 1; i++){
            ans = min(vec[i + 1] - vec[i], ans);
        }
        return ans;
    }

    void fill(vector<int>& vec, TreeNode* root){
       if(!root) return;
       fill(vec, root -> left);
       vec.push_back(root -> val);
       fill(vec, root -> right);
    }
};