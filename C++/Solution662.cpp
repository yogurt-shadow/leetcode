#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<unordered_set>
#include<queue>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct Node
{
    TreeNode *root;
    int depth;
    int index;
    Node(TreeNode *r, int d, int i) : root(r), depth(d), index(i) {}
};

class Solution662
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        int ans = 0;
        queue<Node> q;
        q.push(Node(root, 0, 1));
        while (!q.empty())
        {
            int size = q.size();
            int x = -1, y = -1;
            int start = q.front().index;
            for (int i = 0; i < size; i++)
            {
                auto cur = q.front();
                q.pop();
                if (cur.root->left)
                {
                    q.push(Node(cur.root->left, cur.depth + 1, cur.index * 2 - start * 2));
                    if (x == -1)
                    {
                        x = cur.index * 2 - start * 2;
                    }
                    y = cur.index * 2 - start * 2;
                }
                if (cur.root->right)
                {
                    q.push(Node(cur.root->right, cur.depth + 1, cur.index * 2 + 1 - start * 2));
                    if (x == -1)
                    {
                        x = cur.index * 2 + 1 - start * 2;
                    }
                    y = cur.index * 2 + 1 - start * 2;
                }
            }
            ans = max(ans, y - x + 1);
        }
        return ans;
    }
};