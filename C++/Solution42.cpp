#include<iostream>
#include<vector>

#include<stack>
using namespace std;

class Solution42 {
public:
    int trap(vector<int>& height) {
        stack<int> stk;
        int sum = 0;
        for(int i = 0; i < height.size(); i++){
            if(stk.empty() || height[stk.top()] > height[i]){
                stk.push(i);
                continue;
            }
            int last = 0;
            while(!stk.empty() && height[stk.top()] <= height[i]){
                int index = stk.top();
                int h = height[index];
                sum += (h - last) * (i - index - 1);
                last = h;
                stk.pop();
            }
            if(!stk.empty()){
                int index = stk.top();
                int h = height[index];
                sum += (height[i] - last) * (i - index - 1);
            }
            stk.push(i);
        }
        return sum;
    }
};

int main(){
    Solution42 s;
    vector<int> test = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << s.trap(test);
    return 0;
}