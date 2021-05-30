#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<map>
using namespace std;

class Solution5700 {
public:
    map<int,int>GG[2005];
    vector<pair<int,int>>G[2005];
    int cnt[2005];
    int dp[4000][2];
    int minChanges(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++){
            GG[i%k][nums[i]]++;
            cnt[i%k]++;
        }
        map<int,int>::iterator it;
        for(int i=0;i<k;i++){
            for(it=GG[i].begin();it!=GG[i].end();it++){
                G[i].push_back(*it);
            }
        }
        memset(dp,0x3f,sizeof(dp));
        dp[0][1]=0;
        for(int i=0;i<k;i++){
            int mn=0x3f3f3f3f;
            for(int j=0;j<=1024;j++){
                dp[j][0]=dp[j][1];
                mn=min(mn,dp[j][1]);
            }
            for(int j=0;j<=1024;j++) dp[j][1]=mn+cnt[i];
            for(int j=0;j<G[i].size();j++){
                for(int kk=0;kk<=1024;kk++){
                    dp[kk][1]=min(dp[kk][1],dp[kk^G[i][j].first][0]+cnt[i]-G[i][j].second);
                }
            }
        }
        return dp[0][1];
    }
};