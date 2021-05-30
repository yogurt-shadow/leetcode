#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>

using namespace std;


class Solution1{
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector<int> res(k);
        sort(logs.begin(), logs.end());
        int cur = 0;
        int id = logs[0][0];
        int minute = -1;
        for(auto ele: logs){
            if(ele[0] == id && ele[1] == minute){
                continue;
            }
            if(ele[0] == id && ele[1] != minute){
                cur++;
                minute = ele[1];
            }
            else{
                if(cur <= k) res[cur - 1]++;
                cur = 1;
                minute = ele[1];
                id = ele[0];
            }
        }
        if(cur <= k) res[cur - 1]++;
        return res;
    }
};

int main(){
    vector<vector<int>> vec = {{1, 2}, {1, 1}, {0, 4}};
    sort(vec.begin(), vec.end());
    for(auto ele: vec){
        cout << ele[0] << ele[1] << endl;
    }
    return 0;
}