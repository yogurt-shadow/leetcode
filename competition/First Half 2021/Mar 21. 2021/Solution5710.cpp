#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;

typedef pair<int, int> pii;

class Solution5710 {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        const int MOD = 1000000000 + 7;
        priority_queue<pii> buy;
        priority_queue<pii, vector<pii>, greater<pii>> sell;
        for(auto order: orders){
            int price = order[0];
            int amount = order[1];
            if(order[2] == 0){
                while(!sell.empty()){
                    auto cur = sell.top();
                    if(cur.first > price){
                        break;
                    }
                    if(cur.second > amount){
                        int temp = cur.second - amount;
                        amount = 0;
                        sell.pop();
                        sell.push({cur.first, temp});
                        break;
                    }
                    else{
                        sell.pop();
                        amount -= cur.second;
                    }
                    
                }
                if(amount > 0){
                    buy.push({price, amount});
                }
            }
            else{
                while(!buy.empty()){
                    auto cur = buy.top();
                    if(cur.first < price){
                        break;
                    }
                    if(cur.second > amount){
                        int temp = cur.second - amount;
                        amount = 0;
                        buy.pop();
                        buy.push({cur.first, temp});
                        break;
                    }
                    else{
                        amount -= cur.second;
                        buy.pop();
                    }
                }
                if(amount > 0){
                    sell.push({price, amount});
                }
            }
        }
        long long res = 0;
        while(!buy.empty()){
            res += buy.top().second;
            buy.pop();
            res = res % MOD;
        }
        while(!sell.empty()){
            res += sell.top().second;
            sell.pop();
            res = res % MOD;
        }
        return res;
    }
};

int main(){
    priority_queue<int> pq;
    pq.push(1231);
    pq.push(312);
    while(!pq.empty()){
        cout << pq.top() << endl;
        pq.pop();
    }
    return 0;
}