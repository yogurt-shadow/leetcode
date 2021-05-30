#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<stack>
#include<cstring>

using namespace std;
using ll = long long;

class Solution4 {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        vector<vector<int>> vec(restrictions.begin(), restrictions.end());
        vec.push_back({1, 0});
        sort(vec.begin(), vec.end());
        if(vec.back()[0] != n){
            vec.push_back({n, n - 1});
        }
        for(int i = 1; i < vec.size(); i++){
            vec[i][1] = min(vec[i][1], vec[i - 1][1] + (vec[i][0] - vec[i - 1][0]));
        }
        for(int i = vec.size() - 2; i >= 0; i--){
            vec[i][1] = min(vec[i][1], vec[i + 1][1] + (vec[i + 1][0] - vec[i][0]));
        }
        int h = 0;
        for(int i = 0; i < vec.size() - 1; i++){
            h = max(h, (vec[i + 1][0] - vec[i][0] + vec[i][1] + vec[i + 1][1]) / 2);
        }
        return h;
    }
};

int main(){
    return 0;
}