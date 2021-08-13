#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

typedef long long ll;

class Solution313 {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        unordered_set<ll> st;
        pq.push(1);
        st.insert(1);
        ll cur = 0;
        while(n > 0){
            cur = pq.top();
            pq.pop();
            for(int prime: primes){
                ll x = cur * prime;
                if(!st.count(x)){
                    pq.push(x);
                    st.insert(x);
                }
            }
            n --;
        }
        return cur;
    }
};