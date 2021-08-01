#include<iostream>
#include<vector>
#include<queue>

using namespace std;
typedef pair<int, int> pii;

class Solution1232 {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if(coordinates.size() <= 2){
            return true;
        }
        if(coordinates[0][0] == coordinates[1][0]){
            int x = coordinates[0][0];
            for(int i = 2; i < coordinates.size(); i++){
                if(coordinates[i][0] != x){
                    return false;
                }
            }
            return true;
        }
        double slope = 1.0 * (coordinates[0][1] - coordinates[1][1]) / (coordinates[0][0] - coordinates[1][0]);
        for(int i = 2; i < coordinates.size(); i++){
            int delta_x = coordinates[i][0] - coordinates[0][0];
            int delta_y = coordinates[i][1] - coordinates[0][1];
            if(1.0 * delta_y != delta_x * slope){
                return false;
            }
        }
        return true;
    }
};