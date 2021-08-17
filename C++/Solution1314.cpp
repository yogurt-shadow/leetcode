#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class Solution1314 {
public:
    vector<vector<int>> pre;

    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();
        pre.resize(n + 1, vector<int>(m + 1, 0));
        for(int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                pre[i + 1][j + 1] = pre[i][j + 1] + pre[i + 1][j] - pre[i][j] + mat[i][j];
            }
        }
        vector<vector<int>> ans(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int row1 = max(i - k, 0), row2 = min(i + k, n - 1), col1 = max(j - k, 0), col2 = min(j + k, m - 1);
                ans[i][j] = pre[row2 + 1][col2 + 1] - pre[row1][col2 + 1] - pre[row2 + 1][col1] + pre[row1][col1];
            }
        }
        return ans;
    }
};