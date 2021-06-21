#include<iostream>
#include<vector>
#include<string>

using namespace std;

typedef long long ll;

typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<vii> viii;


class Solution3 {
public:
    int ans = 0;
    int n, m;
    int ans2 = 0;

    bool have = true;

    int xx[4] = {0, 1, 0, -1};
    int yy[4] = {1, 0, -1, 0};

    void dfs(vector<vector<int>> &g, vector<vector<int>> &grid, int x, int y)
    {
        if(g[x][y] == 0){
            have = false;
        }
        grid[x][y] = 0;
        for (int i = 0; i < 4; i++)
        {
            int curx = x + xx[i], cury = y + yy[i];
            if (curx >= 0 && curx < n && cury >= 0 && cury < m && grid[curx][cury] == 1)
            {
                dfs(g, grid, curx, cury);
            }
        }
    }

    int numIslands(vector<vector<int>>& g, vector<vector<int>> &grid)
    {
        n = grid.size();
        m = grid[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    ans++;
                    dfs(g, grid, i, j);
                    if(have){
                        ans2 ++;
                    }
                    have = true;
                }
            }
        }
        return ans;
    }

    int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
    {
        numIslands(grid1, grid2);
        return ans2;
    }
};

int main(){
    
    return 0;
}

