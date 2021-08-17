#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<string>
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

class Solution606 {
public:
    string tree2str(TreeNode* root) {
        string ans;
        if(!root) return ans;
        ans += to_string(root -> val);
        auto left = tree2str(root -> left);
        auto right = tree2str(root -> right);
        if(left == "" && right == ""){
            return ans;
        }
        if(left == ""){
            right = "(" + right + ")";
            return ans + "()" + right;
        }
        if(right == ""){
            left = "(" + left + +")";
            return ans + left;
        }
        left = "(" + left + +")";
        right = "(" + right + +")";
        return ans + left + right;
    }
};

int main(){
    string x;
    x += to_string(123);
    cout << x << endl;
    return 0;
}