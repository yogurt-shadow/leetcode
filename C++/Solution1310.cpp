#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<stack>

using namespace std;
typedef long long ll;

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int size = arr.size();
        vector<int> ans;
        vector<int> sum(size + 1);
        sum[0] = 0;
        for(int i = 1; i <= size; i++){
            sum[i] = sum[i - 1] ^ arr[i - 1];
        }
        for(auto query: queries){
            ans.push_back(sum[query[1] + 1] ^ sum[query[0]]);
        }
        return ans;
    }
};