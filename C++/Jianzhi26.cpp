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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (!A || !B) return false;
        if(recur(A, B)){
            return true;
        }
        return isSubStructure(A -> left, B) || isSubStructure(A -> right, B);
    }

    bool recur(TreeNode* A, TreeNode* B){
        if(!B) return true;
        if(!A) return false;
        return (A -> val == B -> val) && recur(A -> left, B -> left) && recur(A -> right, B -> right);
    }
};