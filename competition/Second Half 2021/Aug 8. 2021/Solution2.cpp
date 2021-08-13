#include <iostream>
#include <vector>
#include<queue>

using namespace std;

class Solution2 {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int sum = 0;
        priority_queue<int, vector<int>> pq;
        for(auto ele: piles){
            sum += ele;
            pq.push(ele);
        }
        while(k > 0){
            k --;
            int x = pq.top();
            pq.pop();
            pq.push(x - x / 2);
            sum -= x / 2;
        }
        return sum;
    }
};
int main(){

    return 0;
}
