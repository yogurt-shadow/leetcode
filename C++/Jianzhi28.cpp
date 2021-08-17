#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return recur(root -> left, root -> right);
    }

    bool recur(TreeNode* A, TreeNode* B){
        if(!A && !B) return true;
        if(!A || !B) return false;
        return (A -> val == B -> val) && recur(A -> right, B -> left) && recur(A -> left, B -> right);
    }
};