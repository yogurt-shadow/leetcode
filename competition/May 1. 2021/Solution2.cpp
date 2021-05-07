#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<queue>

using namespace std;

typedef long long ll;

class SeatManager {
public:
    int n;
    priority_queue<int, vector<int>, greater<int>> pq;

    SeatManager(int n) {
        this-> n = n;
        for(int i = 1; i <= n; i++){
            pq.push(i);
        }
    }
    
    int reserve() {
        int ele = pq.top();
        pq.pop();
        return ele;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */

int main(){
    
    
    return 0;
}