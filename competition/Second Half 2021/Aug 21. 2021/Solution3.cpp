#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

typedef long long ll;
typedef pair<ll, int> pii;

class Solution3 {
public:
    vector<unordered_map<int, long long>> mp;
    vector<int> visited;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<long long> num;
    vector<long long> distance;

    const long long MAX = LLONG_MAX;
    const int MOD = 1e9 + 7;

    int countPaths(int n, vector<vector<int>> &roads){
        mp.resize(n);
        num.resize(n);
        visited.resize(n, 0);
        distance.resize(n, MAX);
        distance[0] = 0;
        num[0] = 1;
        for (auto ele : roads){
            mp[ele[0]][ele[1]] = ele[2];
            mp[ele[1]][ele[0]] = ele[2];
        }
        pq.push({0, 0});
        while (!pq.empty()){
            auto [dist, point] = pq.top();
            pq.pop();
            if (visited[point]){
                continue;
            }
            visited[point] = 1;
            for (auto nei : mp[point]){
                int neighbor = nei.first;
                if (distance[neighbor] == distance[point] + (long long) nei.second){
                    num[neighbor] += num[point];
                    num[neighbor] %= MOD;
                }
                else if (distance[neighbor] > distance[point] + (long long) nei.second){
                    num[neighbor] = num[point];
                    distance[neighbor] = distance[point] + nei.second;
                    pq.push({distance[neighbor], neighbor});
                }
            }
        }
        return num[n - 1];
    }
};

int main(){

    return 0;
}