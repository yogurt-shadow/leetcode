#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class Solution1276 {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        if(tomatoSlices % 2 == 0 && tomatoSlices >= 2 * cheeseSlices && 4 * cheeseSlices >= tomatoSlices){
            return {tomatoSlices / 2 - cheeseSlices, cheeseSlices * 2 - tomatoSlices / 2};
        }
        return vector<int>(0);
    }
};