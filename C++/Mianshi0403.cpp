#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    vector<ListNode*> listOfDepth(TreeNode* tree) {
        vector<ListNode*> ans;
        dfs(ans, tree, 0);
        return ans;
    }

    void dfs(vector<ListNode*>& ans, TreeNode* tree, int depth){
        if(!tree){
            return;
        }
        if(ans.size() <= depth){
            ans.push_back(new ListNode(tree -> val));
        }
        else{
            add(ans[depth], tree -> val);
        }
        dfs(ans, tree -> left, depth + 1);
        dfs(ans, tree -> right, depth + 1);
    }

private:
    void add(ListNode* list, int x){
        while(list -> next){
            list = list -> next;
        }
        list -> next = new ListNode(x);
    }
};