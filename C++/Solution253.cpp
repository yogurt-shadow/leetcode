#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<map>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class Solution253 {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int ans = 0;
        map<int, int> mp;
        for(auto ele: intervals){
            mp[ele[0]]++;
            mp[ele[1]]--;
        }
        int cur = 0;
        for(auto ele: mp){
            cur += ele.second;
            ans = max(ans, cur);
        }
        return ans;
    }
};