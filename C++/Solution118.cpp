#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;


class Solution118 {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        while(numRows > 1){
            auto& last = ans.back();
            vector<int> cur;
            cur.push_back(1);
            for(int i = 0; i + 1 < last.size(); i++){
                cur.push_back(last[i] + last[i + 1]);
            }
            cur.push_back(1);
            ans.push_back(cur);
            numRows --;
        }
        return ans;
    }
};