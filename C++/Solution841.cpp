#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class Solution841 {
public:
    vector<int> have;

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int size = rooms.size();
        have.resize(size, 0);
        dfs(rooms, 0);
        for(auto ele: have){
            if(ele == 0){
                return false;
            }
        }
        return true;
    }

    void dfs(vector<vector<int>>& rooms, int cur){
        have[cur] = 1;
        for(auto other : rooms[cur]){
            if(!have[other]){
                dfs(rooms, other);
            }
        }
    }
};