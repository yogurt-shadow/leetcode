#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution5702 {
public:
    int findCenter(vector<vector<int>>& edges) {
        int x = edges[0][0], y = edges[0][1];
        for(int i = 1; i < edges.size(); i++){
            if(edges[i][0] == x || edges[i][1] == x){
                return x;
            }
            return y;
        }
        return 0;
    }
};