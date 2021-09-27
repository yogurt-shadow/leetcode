#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class Solution502 {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pii> items(profits.size());
        for(int i = 0; i < profits.size(); i++){
            items[i] = {capital[i], profits[i]};
        }
        int size = profits.size();
        sort(items.begin(), items.end(), less<pii>());
        priority_queue<int, vector<int>, less<int>> pq;
        int index = 0;
        while(k > 0){
            while(index < size && items[index].first <= w){
                pq.push(items[index].second);
                index ++;
            }
            if(pq.empty()){
                return w;
            }
            w += pq.top();
            pq.pop();
            k --;
        }
        return w;
    }
};