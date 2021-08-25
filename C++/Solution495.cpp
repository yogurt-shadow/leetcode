#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<map>
#include<math.h>

using namespace std;

class Solution495 {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int ans = 0;
        sort(timeSeries.begin(), timeSeries.end());
        for(int i = 0; i + 1 < timeSeries.size(); i++){
            ans += min(duration, timeSeries[i + 1] - timeSeries[i]);
        }
        ans += duration;
        return ans;
    }
};