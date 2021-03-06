#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution73 {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> row, col;
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    row.insert(i);
                    col.insert(j);
                }
            }
        }

        for(auto ele: row){
            for(int j = 0; j < matrix[0].size(); j++){
                matrix[ele][j] = 0;
            }
        }
        for(auto ele: col){
            for(int i = 0; i < matrix.size(); i++){
                matrix[i][ele] = 0;
            }
        }
    }
};