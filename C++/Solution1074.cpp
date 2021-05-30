#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<stack>

using namespace std;
typedef long long ll;

class Solution1074 {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> sum(n + 1, vector<int>(m + 1));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
        int ans = 0;
        for(int top = 1; top <= n; top++){
            for(int bot = top; bot <= n; bot++){
                unordered_map<int, int> mp;
                for(int right = 1; right <= m; right++){
                    int cur = sum[bot][right] - sum[top - 1][right];
                    if(cur == target){
                        ans++;
                    }
                    ans += mp[cur - target];
                    mp[cur]++;
                }
            }
        }
        return ans;
    }
};