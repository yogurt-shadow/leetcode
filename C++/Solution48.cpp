#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution48 {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size();
        vector<vector<int>> copy(matrix.begin(), matrix.end());
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                matrix[i][j] = copy[size - 1 - j][i];
            }
        }
    }
};

int main(){
    vector<vector<int>> test = {{1, 2}, {2, 3}};
    vector<vector<int>> copy(test.begin(), test.end());
    test[0][1] = 20;
    cout << copy[0][1] << " " << test[0][1];
    return 0;
}