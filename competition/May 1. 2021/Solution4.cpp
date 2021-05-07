#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>


using namespace std;

typedef long long ll;

static bool cmp(vector<int>& node1, vector<int> node2){
    if(node1[1] < node2[1]){
        return true;
    }
    if(node1[1] > node2[1]){
        return false;
    }
    return node1[0] < node2[0];
}

class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        sort(rooms.begin(), rooms.end(), cmp);
        vector<int> ans;
        for(int i = 0; i < queries.size(); i++){
            int minsize = queries[i][1];
            int preid = queries[i][0];
            int index = find1(rooms, minsize);
            //cout << index << endl;
            if(index < 0){
                ans.push_back(-1);
                continue;
            }
            vector<vector<int>> copy(rooms.begin() + index, rooms.end());
            sort(copy.begin(), copy.end());
            //cout << copy.size() << endl;
            int id = find2(copy, preid);
            ans.push_back(id);
        }
        return ans;
    }

    int find2(vector<vector<int>>& copy, int preid){
        int small = 0; int large = copy.size() - 1;
        while(large - small > 1){
            //cout << small << large << endl;
            if(preid >= copy[large][0]){
                return copy[large][0];
            }
            if(preid <= copy[0][0]){
                return copy[0][0];
            }
            int mid = (large - small) / 2 + small;
            if(preid == mid){
                return mid;
            }
            else if(preid > mid){
                small = mid;
            }
            else{
                large = mid;
            }
        }
        return copy[small][0];
    }

    int find1(vector<vector<int>>& rooms, int size){
        if(rooms[rooms.size() - 1][1] < size){
            return -1;
        }
        if(rooms[0][1] >= size){
            return 0;
        }
        int low = 0;
        int large = rooms.size() - 1;
        while(large - low > 1){
            int mid = (large - low) / 2 + low;
            if(rooms[mid][1] >= size && rooms[mid - 1][1] < size){
                return mid;
            }
            if(rooms[mid][1] < size){
                low = mid + 1;
            }
            else{
                large = mid;
            }
        }
        return low;
    }
};

int main(){
    Solution s;
    vector<vector<int>> rooms = {{1, 4}, {2, 3}, {3, 5}, {4, 1}, {5, 2}};
    vector<vector<int>> queries = {{2, 3}};
    auto ele = s.closestRoom(rooms, queries);
    for(auto ele2: ele){
        cout << ele2 << endl;
    }
    return 0;
}