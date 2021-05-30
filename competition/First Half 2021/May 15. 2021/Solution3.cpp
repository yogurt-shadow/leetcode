#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

typedef long long ll;

class Solution3
{
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>> &box)
    {
        int row = box.size();
        int col = box[0].size();
        vector<vector<char>> res(col, vector<char>(row, '.'));
        //cout << res.size() << endl;
        for (int r = 0; r < row; r++)
        {
            for (int l = col - 1; l >= 0; l--)
            {
                if (box[r][l] == '.')
                {
                    continue;
                }
                if (box[r][l] == '*')
                {
                    res[l][row - 1 - r] = '*';
                }
                else
                {
                    int x = l;
                    int y = row - 1 - r;
                    while (x + 1 < col && res[x + 1][y] == '.')
                    {
                        x++;
                    }
                    res[x][y] = '#';
                }
            }
        }
        return res;
    }
};

int main(){

    return 0;
}