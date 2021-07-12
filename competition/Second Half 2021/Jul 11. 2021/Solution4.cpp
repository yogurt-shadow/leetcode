#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <queue>

using ll = long long;

using namespace std;
typedef vector<pair<int, int>> vii;

typedef pair<int, int> pii;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int vals[50005];
public:
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        map<TreeNode*, int> minMap, maxMap;
        for (int i = 0; i < trees.size(); ++i) {
            auto node = trees[i];
            minMap[node] = (node->left == nullptr) ? node->val : node->left->val;
            maxMap[node] = (node->right == nullptr) ? node->val: node->right->val;
            if (node->left) {
                if (vals[node->left->val]) return nullptr;
                vals[node->left->val] = i + 1;
            }
            if (node->right) {
                if (vals[node->right->val]) return nullptr;
                vals[node->right->val] = i + 1;
            }
        }
        TreeNode* root = nullptr;
        for (auto& node: trees) {
            int pos = vals[node->val] - 1;
            if (pos == -1) {
                if (root) return nullptr;
                root = node;
                continue;
            }
            auto findNode = trees[pos];
            if (findNode->left && node->val == findNode->left->val) {
                if (maxMap[node] < findNode->val) {
                    minMap[findNode] = minMap[node];
                    findNode->left = node;
                }
                else return nullptr;
            }
            else {
                if (minMap[node] > findNode->val) {
                    maxMap[findNode] = maxMap[node];
                    findNode->right = node;
                }
                else return nullptr;
            }
        }
        return root;
    }
};


int main(){
   
    
    return 0;
}