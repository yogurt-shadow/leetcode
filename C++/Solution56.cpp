#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution56 {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        int left = intervals[0][0], right = intervals[0][1];
        for(int index = 1; index < intervals.size(); index++){
            if(intervals[index][0] <= right){
                right = max(right, intervals[index][1]);
            }
            else{
                res.push_back({left, right});
                left = intervals[index][0];
                right = intervals[index][1];
            }
        }
        res.push_back({left, right});
        return res;
    }
};


int main(){
   Solution56 s;
    vector<vector<int>> test = {{1, 4}, {4, 5}};
    vector<vector<int>> res = s.merge(test);
    return 0;
 }