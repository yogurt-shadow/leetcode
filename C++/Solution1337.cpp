#include<iostream>
#include<vector>
#include<queue>

using namespace std;
typedef pair<int, int> pii;

struct cmp {
    bool operator()(pii& x, pii& y){
        if(x.first == y.first){
            return x.second > y.second;
        }
        return x.first > y.first;
    }

};


class Solution1337 {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> ans;
        priority_queue<pii, vector<pii>, cmp> pq;
        for(int i = 0; i < mat.size(); i++){
            int sum = 0;
            for(int j = 0; j < mat[0].size(); j++){
                sum += mat[i][j];
            }
            pq.push({sum, i});
        }
        for(int i = 0; i < k; i++){
            auto ele = pq.top();
            pq.pop();
            ans.push_back(ele.second);
        }
        return ans;
    }
};