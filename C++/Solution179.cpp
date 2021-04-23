#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<stack>
#include<queue>

using ll = long long;
using namespace std;

class Solution179 {
public:
    static bool compare(int x, int y){
        ll s1 = 10, s2 = 10;
        while(y >= s1){
            s1 *= 10;
        }
        while(x >= s2){
            s2 *= 10;
        }
        return x * s1 + y > y * s2 + x;
    }

    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), compare);
        string res = "";
        for(auto ele: nums){
             res += to_string(ele);
        }
        if(res.length() >= 1 && res[0] == '0'){
            return "0";
        }
        return res;
    }
};