#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<map>
#include<math.h>

using namespace std;

class Solution5851 {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<string> st;
        for(auto ele: nums){
            st.insert(ele);
        }
        for(int mask = 0; mask < (1 << n); mask++){
            string cur = convert(mask, n);
            if(st.count(cur) == 0){
                return cur;
            }
        }
        return "";
    }

    string convert(int mask, int n){
        string ans;
        for(int i = 0; i < n; i++){
            if((1 << i) & mask){
                ans = "1" + ans;
            }
            else{
                ans = "0" + ans;
            }
        }
        return ans;
    }
};
