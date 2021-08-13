#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

typedef long long ll;

class Solution1014 {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans = INT_MIN;
        int m = values.back() - (values.size() - 1);
        for(int i = values.size() - 2; i >= 0; i--){
            ans = max(ans, values[i] + i + m);
            m = max(m, values[i] - i);
        }
        return ans;
    }
};