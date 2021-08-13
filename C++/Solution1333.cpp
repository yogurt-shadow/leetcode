#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class Solution1333 {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<int> ans;
        priority_queue<pii, vector<pii>, less<pii>> pq;
        for(auto ele: restaurants){
            if((veganFriendly && ele[2] == 0) || ele[3] > maxPrice || ele[4] > maxDistance){
                continue;
            }
            pq.push({ele[1], ele[0]});
        }
        while(!pq.empty()){
            auto ele = pq.top();
            pq.pop();
            ans.push_back(ele.second);
        }
        return ans;
    }
};

int main(){
    int x = 0;
    cout << (x && 0 == 0) << endl;
    return 0;
}