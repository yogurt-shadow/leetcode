#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution802 {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        state.resize(graph.size());
        for(int i = 0; i < graph.size(); i++){
            if(isSafe(i, graph)){
                ans.push_back(i);
            }
        }
        return ans;
    }

private:
    vector<int> state;
    bool isSafe(int x, vector<vector<int>>& graph){
        if(state[x] == 1) return true;
        if(state[x] == 2) return false;
        state[x] = 2;
        for(auto neighbor: graph[x]){
            if(!isSafe(neighbor, graph)) return false;
        }
        state[x] = 1;
        return true;
    }
};