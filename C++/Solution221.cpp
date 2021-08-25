#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<stack>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class Solution221 {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> num(n, vector<int>(m));
        for(int j = 0; j < m; j++){
            num[0][j] = matrix[0][j] - '0';
        }
        for(int row = 1; row < n; row++){
            for(int col = 0; col < m; col++){
                if(matrix[row][col] == '0'){
                    num[row][col] = 0;
                }
                else{
                    num[row][col] = num[row - 1][col] + 1;
                }
            }
        }
        int ans = 0;
        for(int row = 0; row < n; row++){
            stack<int> stk;
            vector<int> left(m), right(m);
            for(int col = 0; col < m; col++){
                while(!stk.empty() && num[row][col] <= num[row][stk.top()]){
                    stk.pop();
                }
                if(stk.empty()){
                    left[col] = -1;
                }
                else{
                    left[col] = stk.top();
                }
                stk.push(col);
            }
            stack<int> stk2;
            for(int col = m - 1; col >= 0; col--){
                while(!stk2.empty() && num[row][col] <= num[row][stk2.top()]){
                    stk2.pop();
                }
                if(stk2.empty()){
                    right[col] = m;
                }
                else{
                    right[col] = stk2.top();
                }
                stk2.push(col);
            }
            for(int col = 0; col < m; col++){
                int x = min(num[row][col], right[col] - left[col] - 1);
                ans = max(ans, x * x);
            }
        }
        return ans;
    }
};
