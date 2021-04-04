#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<stack>

using namespace std;

class Solution17_21 {
public:
    int trap(vector<int>& height) {
        stack<int> stk;
        int res = 0;
        for(int i = 0; i < height.size(); i++){
            int last = -1;
            while(!stk.empty() && height[stk.top()] <= height[i]){
                res += (height[stk.top()] - last) * (i - stk.top() - 1);
                last = height[stk.top()];
                stk.pop();
            }
            if(!stk.empty()){
                res += (height[i] - last) * (i - stk.top() - 1);
            }
            //cout << res << endl;
            stk.push(i);
        }
        return res;
    }
};