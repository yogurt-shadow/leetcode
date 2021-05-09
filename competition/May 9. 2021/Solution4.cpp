#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#include<queue>;

using namespace std;

typedef long long ll;

class Solution4{
public:
    int largestPathValue(string colors, vector<vector<int>> &edges)
    {
        int size = colors.size();
        vector<vector<int>> paths(size);
        vector<int> indegree(size, 0);
        vector<vector<int>> f(size, vector<int>(26, 0));
        for(auto ele: edges){
            indegree[ele[1]] ++;
            paths[ele[0]].push_back(ele[1]);
        }
        queue<int> q;
        for(int i = 0; i < size; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        int found = 0;
        while(!q.empty()){
            found ++;
            int cur = q.front();
            q.pop();
            f[cur][colors[cur] - 'a'] ++;
            for(int neighbor: paths[cur]){
                indegree[neighbor] --;
                if(indegree[neighbor] == 0){
                    q.push(neighbor);
                }
                for(int i = 0; i < 26; i++){
                    f[neighbor][i] = max(f[neighbor][i], f[cur][i]);
                }
            }
        }
        if(found != size){
            return -1;
        }
        int ans = 0;
        for(int i = 0; i < size; i++){
            ans = max(ans, *max_element(f[i].begin(), f[i].end()));
        }
        return ans;
    }
};