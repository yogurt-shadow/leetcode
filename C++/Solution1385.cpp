#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution1385 {
public:
    int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d)
    {
        int ans = 0;
        for (auto n1 : arr1)
        {
            bool check = true;
            for (auto n2 : arr2)
            {
                if (abs(n2 - n1) <= d)
                {
                    check = false;
                    break;
                }
            }
            if (check)
            {
                ans++;
            }
        }
        return ans;
    }
};