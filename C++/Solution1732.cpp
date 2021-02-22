#include<iostream>
#include<vector>

using namespace std;

class Solution1732 {
public:
    int largestAltitude(vector<int>& gain) {
        int result = 0, cur = 0;
        for(auto ele: gain){
            cur += ele;
            result = max(result, cur);
        }
        return result;
    }
};