#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<stack>
#include<queue>

using namespace std;
typedef long long ll;

class Solution1701 {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        ll time = 0;
        ll sum = 0;
        for(int i = 0; i < customers.size(); i++){
            ll cur = customers[i][0];
            time = max(time, cur);
            sum += (time - cur + customers[i][1]);
            time += customers[i][1];
        }
        return sum * 1.0 / customers.size()* 1.0;
    }
};