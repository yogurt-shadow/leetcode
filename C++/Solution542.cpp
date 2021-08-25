#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class Solution542 {
public:
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m, -1));
        queue<pii> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    q.push({i, j});
                    ans[i][j] = 0;
                }
            }
        }
        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();
            for(int k = 0; k < 4; k++){
                int curx = x + dir[k][0], cury = y + dir[k][1];
                if(curx >= 0 && curx < n && cury >= 0 && cury < m && ans[curx][cury] == -1){
                    ans[curx][cury] = ans[x][y] + 1;
                    q.push({curx, cury});
                }
            
            }
        }
        return ans;
    }
};