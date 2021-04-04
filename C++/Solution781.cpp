#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<stack>

using namespace std;
typedef long long ll;

class Solution781 {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> mp;
        for(auto ele: answers){
            mp[ele]++;
        }
        int ans = 0;
        for(auto ele: mp){
            int y = ele.first;
            int x = ele.second;
            int cur = (x % (y + 1)) == 0 ? x / (y + 1) : x / (y + 1) + 1;
            ans += cur * (y + 1);
        }
        return ans;
    }
};