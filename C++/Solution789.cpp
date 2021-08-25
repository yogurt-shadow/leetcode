#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class Solution789 {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        vector<int> start = {0, 0};
        int dist = manhattan(start, target);
        for(auto ele: ghosts){
            int cur = manhattan(ele, target);
            if(cur <= dist){
                return false;
            }
        }
        return true;
    }

    int manhattan(vector<int>& vec1, vector<int>& vec2){
        return abs(vec1[0] - vec2[0]) + abs(vec1[1] - vec2[1]);
    }
};