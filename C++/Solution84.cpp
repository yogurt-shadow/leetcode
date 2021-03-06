#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<stack>
using namespace std;

class Solution84 {
public:
    int largestRectangleArea(vector<int>& heights) {
        int size = heights.size();
        vector<int> left(size), right(size);
        stack<int> stk, stk2;
        for(int i = 0; i < size; i++){
            while(!stk.empty() && heights[i] <= heights[stk.top()]){
                stk.pop();
            }
            if(stk.empty()){
                left[i] = -1;
            }
            else{
                left[i] = stk.top();
            }
            stk.push(i);
        }
        for(int i = size - 1; i >= 0; i--){
            while(!stk2.empty() && heights[i] <= heights[stk2.top()]){
                stk2.pop();
            }
            if(stk2.empty()){
                right[i] = size;
            }
            else{
                right[i] = stk2.top();
            }
            stk2.push(i);
        }
        int area = 0;
        for(int i = 0; i < size; i++){
            area = max(area, heights[i] * (right[i] - left[i] - 1));
        }
        return area;
    }
};