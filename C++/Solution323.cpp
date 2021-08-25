#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<map>
using namespace std;

class Solution323 {
public:
    vector<int> visit;
    vector<unordered_set<int>> vec;

    int countComponents(int n, vector<vector<int>> &edges){
        visit.resize(n);
        vec.resize(n);
        for(auto ele: edges){
            vec[ele[0]].insert(ele[1]);
            vec[ele[1]].insert(ele[0]);
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(!visit[i]){
                dfs(i);
                ans++;
            }
        }
        return ans;
    }

    void dfs(int x){
        visit[x] = 1;
        for(auto ele: vec[x]){
            if(!visit[ele]){
                dfs(ele);
            }
        }
    }
};