#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <queue>

using ll = long long;

using namespace std;
typedef vector<pair<int, int>> vii;

typedef pair<int, int> pii;

class Solution2 {
public:
    int smallestChair(vector<vector<int>> &times, int targetFriend)
    {
        int start = times[targetFriend][0];
        int n = times.size();
        sort(times.begin(), times.end());
        vector<int> dp(n, 0), occ(n, 0);
        priority_queue<pii, vector<pii>, greater<pii>> lea;
        int index = 0, ans = 0;
        for (; index < n && times[index][0] <= start; index++)
        {
            int cur1 = times[index][0], cur2 = times[index][1];
            //cout << index <<" " << cur1 << " " << cur2 << endl;

            while (!lea.empty() && cur1 >= lea.top().first)
            {
                //cout << ":dasd" << endl;
                auto cur = lea.top();
                //cout << cur.first << " " << cur.second << endl;
                lea.pop();
                occ[dp[cur.second]] = 0;
            }
            for (int i = 0; i < n; i++)
            {
                if (occ[i] == 0)
                {
                    dp[index] = i;
                    occ[i] = 1;
                    break;
                }
            }
            ans = dp[index];
            //cout << "dp: " << index << dp[index] << endl;
            lea.push({cur2, index});
        }
        //cout << endl;

        return ans;
    }
};

int main(){
    priority_queue<int, vector<int>> pq;
    for(int i = 0; i < 10; i++){
        pq.push(i);
    }
    while(!pq.empty()){
        auto& ele1 = pq.top();
        auto ele2 = pq.top();
        pq.pop();
        cout << ele1 <<  endl;
        cout << ele2 << endl;
    }
    return 0;
}