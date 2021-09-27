#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>

using namespace std;

typedef long long ll;

class Solution1109 {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        unordered_map<int, int> mp;
        for(auto& ele: bookings){
            mp[ele[0]] += ele[2];
            mp[ele[1] + 1] -= ele[2];
        }
        vector<int> ans;
        int cur = 0;
        for(int i = 1; i <= n; i++){
            cur += mp[i];
            ans.push_back(cur);
        }
        return ans;
    }
};