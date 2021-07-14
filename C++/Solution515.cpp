#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<queue>

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
 
class Solution515 {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> vec;
        if(!root){
            return vec;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            int ans = INT_MIN;
            for(int i = 0; i < size; i++){
                auto cur = q.front();
                q.pop();
                ans = max(ans, cur -> val);
                if(cur -> left){
                    q.push(cur -> left);
                }
                if(cur -> right){
                    q.push(cur -> right);
                }
            }
            vec.push_back(ans);
        }
        return vec;
    }
};