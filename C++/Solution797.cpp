#include<iostream>
#include<vector>
#include<map>
#include<unordered_set>

using namespace std;

class Solution797 {
public:
    vector<vector<int>> ans;
    vector<int> cur;

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        dfs(graph, 0);
        return ans;
    }

    void dfs(vector<vector<int>>& graph, int x){
        if(x == graph.size() - 1){
            cur.push_back(x);
            ans.push_back(cur);
            cur.pop_back();
            return;
        }
        cur.push_back(x);
        for(auto neighbor: graph[x]){
            dfs(graph, neighbor);
        }
        cur.pop_back();
    }
};