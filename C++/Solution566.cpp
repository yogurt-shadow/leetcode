#include<iostream>
#include<vector>

using namespace std;

class Solution566 {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int x = nums.size();
        int y = nums[0].size();
        if(x * y != r * c){
            return nums;
        }
        vector<int> copy(x * y);
        int index = 0;
        for(auto& ele: nums){
            for(auto& ele2: ele){
                copy[index] = ele2;
                index += 1;
            }
        }
        index = 0;
        vector<vector<int>> result(r, vector<int>(c));
        for(int row = 0; row < r; row++){
            for(int col = 0; col < c; col++){
                result[row][col] = copy[index];
                index += 1;
            }
        }
        return result;
    }
};

int main(){
    Solution566 s;
    vector<vector<int>> test = {{1, 2}, {3, 4}};
    vector<vector<int>> res = s.matrixReshape(test, 1, 4);
    for(auto& ele: res){
        for(auto& ele2: ele){
            cout << ele2 << " ";
        }
        cout << endl;
    }
}