#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#include<stack>

using namespace std;

typedef long long ll;

class Solution1{
public:
    const int MOD = 1000000000 + 7;

    int maxSumMinProduct(vector<int> &nums)
    {
        stack<int> stk;
        int size = nums.size();
        vector<ll> sum(size);
        sum[0] = nums[0];
        for(int i = 1; i < size; i++){
            sum[i] = sum[i - 1] + nums[i];
        }
        vector<int> left(size), right(size);
        for(int i = 0; i < nums.size(); i++){
            while(!stk.empty() && nums[stk.top()] > nums[i]){
                int cur = stk.top();
                stk.pop();
                right[cur] = i;
            }
            stk.push(i);
        }
        while(!stk.empty()){
            int cur = stk.top();
            right[cur] = size;
            stk.pop();
        }
        for(int i = size - 1; i >= 0; i--){
            while(!stk.empty() && nums[stk.top()] > nums[i]){
                int cur = stk.top();
                stk.pop();
                left[cur] = i;
            }
            stk.push(i);
        }
        while(!stk.empty()){
            int cur = stk.top();
            left[cur] = -1;
            stk.pop();
        }
        ll ans = 0;
        for(int i = 0; i < size; i++){
            ll cur = nums[i];
            ll other;
            if(left[i] == -1){
                other = cur * sum[right[i] - 1];   
            }
            else{
                other = cur * sum[right[i] - 1] - sum[left[i]];
            }
            ans = max(ans, other);
        }
        return ans % MOD;
    }
};

int main(){

    
    return 0;
}