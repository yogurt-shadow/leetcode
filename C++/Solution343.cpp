#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<stack>
using namespace std;

class Solution343 {
public:
    int integerBreak(int n) {
        vector<int> vec(n + 1);
        vec[1] = 1;
        vec[2] = 1;
        for(int j = 3; j <= n; j++){
            int res = 0;
            for(int i = 1; i < j; i++){
                int cur = max(vec[i], i) * max(j - i, vec[j - i]);
                res = max(res, cur);
            }
            vec[j] = res;
        }
        return vec[n];
    }
};