#include<iostream>
#include<vector>

using namespace std;

class SubrectangleQueries {
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        row = rectangle.size();
        col = rectangle[0].size();
        dp = rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for(int row = row1; row <= row2; row++){
            for(int col = col1; col <= col2; col++){
                dp[row][col] = newValue;
            }
        }
    }
    
    int getValue(int row, int col) {
        return dp[row][col];
    }
private:
    int row, col;
    vector<vector<int>> dp;
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */

int main(){
    vector<vector<int>> test = {{1, 2, 3}, {4, 5, 6}};
    SubrectangleQueries s(test);
    return 0;
}