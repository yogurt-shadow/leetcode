#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<stack>
#include<queue>

using ll = long long;
using namespace std;

class Solution264 {
public:
    int nthUglyNumber(int n) {
        unordered_set<ll> st;
        vector<ll> vec(1691);
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        int times[] = {2, 3, 5};
        pq.push(1);
        st.insert(1);
        for(int i = 1; i <= 1690; i++){
            ll cur = pq.top();
            //cout << cur << endl;
            pq.pop();
            vec[i] = cur;
            for(int j = 0; j < 3; j++){
                ll next = cur * times[j];
                if(st.count(next)){
                    continue;
                }
                st.insert(next);
                pq.push(next);
            }
        }
        return vec[n];
    }
};

int main(){
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(1);
    pq.push(2);
    while(!pq.empty()){
        cout << pq.top() << endl;
        pq.pop();
    }
    return 0;
}
