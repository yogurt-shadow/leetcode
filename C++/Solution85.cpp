#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<stack>
using namespace std;

class Solution85 {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0){
            return 0;
        }
        vector<vector<int>> rect(matrix.size(), vector<int>(matrix[0].size()));
        for(int i = 0; i < matrix[0].size(); i++){
            rect[0][i] = matrix[0][i] - '0';
        }
        for(int i = 1; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == '0'){
                    rect[i][j] = 0;
                }
                else{
                    rect[i][j] = 1 + rect[i - 1][j];
                }
            }
        }
        int area = 0;
        int size = matrix[0].size();
        for(int row = 0; row < matrix.size(); row++){
            vector<int> left(size), right(size);
            stack<int> stk1, stk2;
            for(int i = 0; i < size; i++){
                while(!stk1.empty() && rect[row][i] <= rect[row][stk1.top()]){
                    stk1.pop();
                }
                if(stk1.empty()){
                    left[i] = -1;
                }
                else{
                    left[i] = stk1.top();
                }
                stk1.push(i);
            }

            for(int i = size - 1; i >= 0; i--){
                while(!stk2.empty() && rect[row][i] <= rect[row][stk2.top()]){
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
            for(int i = 0; i < size; i++){
                area = max(area, rect[row][i] * (right[i] - left[i] - 1));
            }
        }
        return area;
    }
};