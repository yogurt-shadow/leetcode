#include <iostream>
#include <vector>

#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution200
{
public:
    int ans = 0;
    int n, m;

    int xx[4] = {0, 1, 0, -1};
    int yy[4] = {1, 0, -1, 0};

    void dfs(vector<vector<char>> &grid, int x, int y)
    {
        grid[x][y] = '0';
        for (int i = 0; i < 4; i++)
        {
            int curx = x + xx[i], cury = y + yy[i];
            if (curx >= 0 && curx < n && cury >= 0 && cury < m && grid[curx][cury] == '1')
            {
                dfs(grid, curx, cury);
            }
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        n = grid.size();
        m = grid[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1')
                {
                    ans++;
                    dfs(grid, i, j);
                }
            }
        }
        return ans;
    }
};