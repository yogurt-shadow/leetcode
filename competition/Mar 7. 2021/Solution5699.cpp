#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int mod = 1000000000 + 7;

struct cmp{
    bool operator()(pii& a, pii& b) const {
        return a.second > b.second;
    }
};

class Solution5699 {
public:
    int size;
    vector<int> dist;
    vector<unordered_map<int, int>> map;
    vector<int> mem;

    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        size = n;
        mem.resize(n, -1);
        dist.resize(n, INT_MAX);
        dist[n - 1] = 0;
        map.resize(n);
        vector<int> visit(n, 0);
        for(auto edge: edges){
            map[edge[0] - 1][edge[1] - 1] = edge[2];
            map[edge[1] - 1][edge[0] - 1] = edge[2];
        }
        priority_queue<pii, vector<pii>, cmp> pq;
        pq.push({n - 1, 0});
        while(!pq.empty()){
            pii cur = pq.top();
            pq.pop();
            int id = cur.first;
            int dis = cur.second;
            if(visit[id]){
                continue;
            }
            visit[id] = 1;
            for(auto it = map[id].begin(); it != map[id].end(); it++){
                int id2 = it -> first;
                if(visit[id2]){
                    continue;
                }
                dist[id2] = min(dist[id2], it -> second + dis);
                pq.push({id2, dist[id2]});
            }
        }
        int cnt = (int) findpaths(0, n - 1);
        return cnt;
    }

    ll findpaths(int start, int end){
        if(start == end){
            return 1;
        }
        if(mem[start] != -1){
            return mem[start];
        }
        ll cnt = 0;
        for(auto it = map[start].begin(); it != map[start].end(); it++){
            int next = it -> first;
            if(dist[next] < dist[start]){
                cnt += findpaths(next, end);
                cnt = cnt % mod;
            }
        }
        mem[start] = cnt;
        return cnt;
    }
};

int main(){
    Solution5699 s;
    vector<vector<int>> edges = {{1,2,3},{1,3,3},{2,3,1},{1,4,2},{5,2,2},{3,5,1},{5,4,10}};
    cout << s.countRestrictedPaths(5, edges);
}