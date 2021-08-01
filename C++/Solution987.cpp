#include<iostream>
#include<vector>
#include<queue>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VII;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct cmp {
    bool operator()(vector<int>& vec1, vector<int>& vec2){
        for(int i = 0; i < 3; i++){
            if(vec1[i] != vec2[i]){
                return vec1[i] > vec2[i];
            }
        }
        return false;
    }
};

class Solution987 {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root, 0, 0);
        vector<vector<int>> ans;
        vector<int> vec;
        if(!root){
            return ans;
        }
        int col = pq.top()[0];
        while(!pq.empty()){
            auto ele = pq.top();
            pq.pop();
            if(ele[0] == col){
                vec.push_back(ele[2]);
            }
            else{
                ans.push_back(vec);
                vec.resize(0);
                vec.push_back(ele[2]);
                col = ele[0];
            }
        }
        ans.push_back(vec);
        return ans;
    }

private:
    priority_queue<VI, VII, cmp> pq;

    void dfs(TreeNode* root, int row, int col){
        if(!root){
            return;
        }
        pq.push({col, row, root -> val});
        dfs(root -> left, row + 1, col - 1);
        dfs(root -> right, row + 1, col + 1);
    }
};