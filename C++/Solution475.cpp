#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;

typedef long long ll;

class Solution475 {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int index = 0;
        int ans = 0;
        for(auto ele: houses){
            while(index + 1 < heaters.size() && ele > heaters[index]){
                index ++;
            }
            int r = INT_MAX;
            if(index - 1 >= 0){
                r = ele - heaters[index - 1];
            }
            r = min(r, abs(ele - heaters[index]));
            ans = max(ans, r);
        }
        return ans;
    }
};