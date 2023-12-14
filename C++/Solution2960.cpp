#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<map>
#include<math.h>

using namespace std;

class Solution2960 {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int descend = 0;
        int count = 0;
        for(int i = 0; i < batteryPercentages.size(); i++) {
            if(batteryPercentages[i] - descend > 0) {
                count++;
                descend++;
            }
        }
        return count;
    }
};