#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>

using namespace std;

typedef long long ll;

class Solution1588 {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int ans = 0;
        vector<int> pre(arr.size() + 1);
        for(int i = 1; i <= arr.size(); i++){
            pre[i] = pre[i - 1] + arr[i - 1];
            for(int j = 0; j <= i; j++){
                if((i - j) % 2 == 1){
                    ans += pre[i] - pre[j];
                }
            }
        }
        return ans;
    }
};