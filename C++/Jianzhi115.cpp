#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<string>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class Solution {
public:
    bool sequenceReconstruction(vector<int> &org, vector<vector<int>> &seqs)
    {
        int n = org.size();
        if (seqs.size() == 0){
            return false;
        }
        vector<unordered_set<int>> edges(n + 1);
        vector<int> deg(n + 1);
        for (auto &ele : seqs){
            if (ele[0] <= 0 || ele[0] > n){
                return false;
            }
            for (int k = 0; k + 1 < ele.size(); k++){
                if (ele[k + 1] <= 0 || ele[k + 1] > n){
                    return false;
                }
                if (edges[ele[k]].count(ele[k + 1]) == 0){
                    edges[ele[k]].insert(ele[k + 1]);
                    deg[ele[k + 1]]++;
                }
            }
        }
        queue<int> q;
        vector<int> ans;
        for (int i = 1; i <= n; i++){
            if (deg[i] == 0){
                q.push(i);
            }
        }
        while (!q.empty()){
            if (q.size() > 1){
                return false;
            }
            auto point = q.front();
            q.pop();
            ans.push_back(point);
            for (auto ele : edges[point]){
                deg[ele]--;
                if (deg[ele] == 0){
                    q.push(ele);
                }
            }
        }
        if (ans.size() != n){
            return false;
        }
        for (int i = 0; i < n; i++){
            if (ans[i] != org[i]){
                return false;
            }
        }
        return true;
    }
};