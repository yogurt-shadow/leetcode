#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;


class Solution1583 {
public:
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        vector<vector<int>> relation(n, vector<int>(n));
        for(int i = 0; i < preferences.size(); i++){
            for(int j = 0; j < preferences[i].size(); j++){
                relation[i][preferences[i][j]] = j;
            }
        }
        vector<int> partner(n);
        for(auto& ele: pairs){
            partner[ele[0]] = ele[1];
            partner[ele[1]] = ele[0];
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            int part = partner[i];
            for(int j = 0; j < n; j++){
                if(j == i || j == part) continue;
                if(relation[i][j] < relation[i][part] && relation[j][i] < relation[j][partner[j]]){
                    ans ++;
                    break;
                }
            }
        }
        return ans;
    }
};