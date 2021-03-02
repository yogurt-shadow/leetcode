#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution62 {
public:
    int uniquePaths(int m, int n) {
        return combine(m + n - 2, m - 1);
    }

    int combine(int x, int y){
        long long res = 1;
        for(int up = x - y + 1, bottom = 1; bottom <= y; bottom++, up++){
            res = res * up / bottom;
        }
        return res;
    }
};