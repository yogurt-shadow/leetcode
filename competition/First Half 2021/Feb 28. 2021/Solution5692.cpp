#include<iostream>
#include<vector>

#include<algorithm>
#include<stack>

using namespace std;

class Solution5692 {
public:

    double calTime(int pos1, int spd1, int pos2, int spd2){
        if(spd1 <= spd2){
            return -1;
        }
        return (double) (pos2 - pos1) / (double) (spd1 - spd2);
    }

    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int size = cars.size();
        vector<double> res(size);
        stack<int> stk;
        for(int i = size - 1; i >= 0; i--){
            while(stk.size() > 0 && res[stk.top()] > 0 && (cars[i][1] <= cars[stk.top()][1] || 
            calTime(cars[i][0], cars[i][1], cars[stk.top()][0], cars[stk.top()][1]) > res[stk.top()])){
                stk.pop();
            }
            if(stk.empty() || cars[i][1] <= cars[stk.top()][1]){
                res[i] = -1;
            }
            else{
                res[i] = calTime(cars[i][0], cars[i][1], cars[stk.top()][0], cars[stk.top()][1]);
            }
            stk.push(i);
        }
        return res;
    }
};