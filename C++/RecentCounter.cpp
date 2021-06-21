#include <iostream>
#include <vector>

#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;


class RecentCounter {
public:
    queue<int> q;

    RecentCounter() {

    }
    
    int ping(int t) {
        q.push(t);
        int cur = 0;
        while(!q.empty() && q.front() < t - 3000){
            q.pop();
        }
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */