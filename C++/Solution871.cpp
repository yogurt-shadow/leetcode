#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class Solution871 {
public:
    int minRefuelStops(int num, int initWater, vector<vector<int>> &supplyStations){
        sort(supplyStations.begin(), supplyStations.end());
        int size = supplyStations.size();
        vector<int> dp;
        unordered_set<int> have;
        dp.push_back(initWater);
        while (dp.back() < num){
            int m = 0, i = -1;
            for (int index = 0; index < size && supplyStations[index][0] <= dp.back(); index++){
                if (have.count(index)){
                    continue;
                }
                if (supplyStations[index][1] > m){
                    m = supplyStations[index][1];
                    i = index;
                }
            }
            have.insert(i);
            dp.push_back(dp.back() + m);
            if (m == 0){
                return -1;
            }
        }
        return dp.size() - 1;
    }
};