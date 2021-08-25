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

class Solution {
public:
    unordered_set<int> value;

    bool findTarget(TreeNode* root, int k) {
        return dfs(root, k);
    }

    bool dfs(TreeNode* node, int k){
        if(!node){
            return false;
        }
        if(value.count(k - node -> val)){
            return true;
        }
        value.insert(node -> val);
        return dfs(node -> left, k) || dfs(node -> right, k);
    }
};