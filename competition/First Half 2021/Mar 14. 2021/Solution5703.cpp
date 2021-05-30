#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

typedef pair<double, double> pii;

struct cmp{
    bool operator()(pii& v1, pii& v2) const {
        return (v1.first - v1.second) / (v1.second * (v1.second + 1)) > (v2.first - v2.second) / (v2.second * (v2.second + 1));
    }
};

class Solution5704 {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pii, vector<pii>, cmp> pq;
        for(int i = 0; i < classes.size(); i++){
            double x = classes[i][0] * 1.0;
            double y = classes[i][1] * 1.0;
            pq.push({x, y});
        }
        while(extraStudents > 0){
            pii cur = pq.top();
            pq.pop();
            double x = cur.first + 1;
            double y = cur.second + 1;
            pq.push({x, y});
            extraStudents--;
        }
        double res = 0;
        while(!pq.empty()){
            pii cur = pq.top();
            pq.pop();
            res += cur.first / cur.second;
        }
        return res / classes.size();
    }
};