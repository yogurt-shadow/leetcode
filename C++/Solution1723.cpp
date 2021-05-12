#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<stack>

using namespace std;
typedef long long ll;

class Solution1723 {
public:
    bool check(vector<int>& jobs, int k, int limit){
        vector<int> works(k, 0);
        return dfs(jobs, works, limit, 0);
    }

    bool dfs(vector<int>& jobs, vector<int>& works, int limit, int index){
        if(index >= jobs.size()){
            return true;
        }
        int cur = jobs[index];
        for(int i = 0; i < works.size(); i++){
            if(works[i] + cur <= limit){
                works[i] += cur;
                if(dfs(jobs, works, limit, index + 1)){
                    return true;
                }
                works[i] -= cur;
            }
            if(works[i] == 0 || works[i] + cur == limit) return false;
        }
        return false;
    }

    int minimumTimeRequired(vector<int>& jobs, int k) {
        sort(jobs.begin(), jobs.end(), greater<int>());
        int left = 0, right = 0;
        for(auto job: jobs){
            left = max(left, job);
            right += job;
        }
        while(right - left > 0){
            int mid = (right - left) / 2 + left;
            if(check(jobs, k, mid)){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        return left;
    }
};