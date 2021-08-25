#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class Solution4_2 {
public:
    int minSupplyTimes(int num, int initWater, vector<vector<int>>& supplyStations) {
        sort(supplyStations.begin(), supplyStations.end());
        int index = 0;
        int far = initWater;
        int ans = 0;
        priority_queue<int, vector<int>, less<int>> pq;
        while(far < num){
            while(index < supplyStations.size() && supplyStations[index][0] <= far){
                pq.push(supplyStations[index++][1]);
            }
            if(pq.empty()){
                return -1;
            }
            far += pq.top();
            pq.pop();
            ans++;
        }   
        return ans;
    }
};