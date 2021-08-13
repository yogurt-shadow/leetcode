#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;

class Solution1334 {
public:
    int dist[100][100];
    unordered_map<int, unordered_map<int, int>> mp;
    int num[100];

    static bool cmp(pii& a, pii& b){
        if(a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    }


    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        memset(dist, INF, sizeof(dist));
        for(auto& edge: edges){
            mp[edge[0]][edge[1]] = edge[2];
            mp[edge[1]][edge[0]] = edge[2];
        }
        for(int i = 0; i <= n - 1; i++){
            dij(i);
        }
        /*
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << i << " " << j << " " << dist[i][j] << endl;
            }
        }
        */
       vector<pii> vec;
        for(int i = 0; i < n; i++){
            int cur = 0;
            for(int j = 0; j < n; j++){
                if(j == i) continue;
                if(dist[i][j] <= distanceThreshold) cur ++;
            }
            vec.push_back({cur, i});
        }
        sort(vec.begin(), vec.end(), cmp);
        return vec.front().second;
    }

    void dij(int start){
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        unordered_set<int> st;
        dist[start][start] = 0;
        pq.push({0, start});
        while(!pq.empty()){
            auto point = pq.top().second;
            pq.pop();
            if(st.count(point)){
                continue;
            }
            st.insert(point);
            for(auto neighbor: mp[point]){
                int nei = neighbor.first;
                dist[start][nei] = min(dist[start][nei], dist[start][point] + mp[point][nei]);
                pq.push({dist[start][nei], nei});
            }
        }
    }
};