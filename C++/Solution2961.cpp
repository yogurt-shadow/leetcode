#include <iostream>
#include <cmath>
#include<vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution2961 {
public:
    long long pow(long long x, int n, int m) {
        long long res = 1;
        for (; n; n /= 2) {
            if (n % 2) res = res * x % m;
            x = x * x % m;
        }
        return res;
    }

public:
    vector<int> getGoodIndices(vector<vector<int>> &variables, int target) {
        vector<int> ans;
        for (int i = 0; i < variables.size(); i++) {
            auto &v = variables[i];
            if (pow(pow(v[0], v[1], 10), v[2], v[3]) == target) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

int main() {
    
   return 0;
}