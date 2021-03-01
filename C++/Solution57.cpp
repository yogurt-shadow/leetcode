#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution57 {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int left = newInterval[0], right = newInterval[1];
        bool put = false;
        for(int index = 0; index < intervals.size(); index++){
            if((intervals[index][0] >= left && intervals[index][0] <= right) || (left >= intervals[index][0] && left <= intervals[index][1])){
                left = min(left, intervals[index][0]);
                right = max(right, intervals[index][1]);
                if(index == 3){
                cout << left << " " << right << endl;
            }
            }
            else if(left > intervals[index][0]){
                res.push_back(intervals[index]);
            }
            else{
                if(!put){
                    res.push_back({left, right});
                    put = true;
                }
                res.push_back(intervals[index]);
            }
        }
        if(!put){
            res.push_back({left, right});
        }
        return res;
    }
};

int main(){
    Solution57 s;
    vector<vector<int>> test = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    vector<int> interval = {4, 8};
    vector<vector<int>> res = s.insert(test, interval);
    return 0;
}