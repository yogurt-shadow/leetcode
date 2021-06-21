#include<iostream>
#include<vector>
#include<string>

using namespace std;

typedef long long ll;

typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<vii> viii;

class Solution4 {
public:
    vector<int> minDifference(vector<int> &nums, vector<vector<int>> &queries)
    {
        int size = nums.size();
        vii sum(size + 1, vi(101));
        sum[1][nums[0]] ++;
        for(int i = 2; i <= size; i++){
            sum[i] = sum[i - 1];
            sum[i][nums[i - 1]] ++;
        }
        vector<int> ans;
        for(auto ele: queries){
            int left = ele[0], right = ele[1];
            int cur = INT_MAX, last = -1;
            for(int i = 1; i <= 100; i++){
                if(sum[right + 1][i] != sum[left][i]){
                    if(last != -1){
                        cur = min(cur, i - last);
                    }
                    last = i;
                }
            }
            if(cur == INT_MAX){
                ans.push_back(-1);
            }
            else{
                ans.push_back(cur);
            }
        }
        return ans;
    }
};

int main(){
    
    return 0;
}