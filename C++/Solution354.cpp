#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

class Solution354 {
public:
    static bool compare(vector<int>& vec1, vector<int>& vec2){
        if(vec1[0] < vec2[0]){
            return true;
        }
        if(vec1[0] == vec2[0] && vec1[1] <= vec2[1]){
            return true;
        }
        return false;
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if(envelopes.size() == 0){
            return 0;
        }
        sort(envelopes.begin(), envelopes.end(), compare);
        int size = envelopes.size();
        vector<int> dp(size);
        dp[0] = 1;
        for(int i = 1; i < size; i++){
            int mm = 0;
            for(int j = 0; j < i; j++){
                if(envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1]){
                    mm = max(mm, dp[j]);
                }
            }
            dp[i] = mm + 1;
        }
        int res = 0;
        for(auto ele: dp){
            res = max(res, ele);
        }
        return res;
    }
};