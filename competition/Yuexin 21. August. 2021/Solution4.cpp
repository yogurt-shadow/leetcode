#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class Solution4 {
public:
    int minSupplyTimes(int num, int initWater, vector<vector<int>> &supplyStations){
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

int main(){

    
    return 0;
}

/*
100
10
[[10,60],[20,30],[30,30],[60,40]]

1000
83
[[15,457],[156,194],[160,156],[230,314],[390,159],[621,20],[642,123],[679,301],[739,229],[751,174]]

1000
299
[[13,21],[26,115],[100,47],[225,99],[299,141],[444,198],[608,190],[636,157],[647,255],[841,123]]
*/