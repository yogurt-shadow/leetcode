#include <iostream>
#include <vector>

#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <map>
#include <set>

using namespace std;

class Solution1 {
public:
    bool match(vector<vector<int>> &mat, vector<vector<int>> &target)
    {
        for (int i = 0; i < mat.size(); i++)
        {
            for (int j = 0; j < mat.size(); j++)
            {
                if (mat[i][j] != target[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool findRotation(vector<vector<int>> &mat, vector<vector<int>> &target)
    {
        if (match(mat, target))
        {
            return true;
        }
        for (int i = 0; i < 3; i++)
        {
            vector<vector<int>> copy(mat.size(), vector<int>(mat.size()));
            for (int l = 0; l < mat.size(); l++)
            {
                for (int m = 0; m < mat.size(); m++)
                {
                    copy[l][m] = mat[mat.size() - 1 - m][l];
                }
            }
            mat = copy;
            if (match(mat, target))
            {
                return true;
            }
        }
        return false;
    }
};