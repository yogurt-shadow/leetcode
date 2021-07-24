#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <stack>

using ll = long long;

using namespace std;
typedef vector<pair<int, int>> vii;

typedef pair<int, int> pii;

class Solution4 {
public:
    vector<int> canSeePersonsCount(vector<int> &heights)
    {
        int size = heights.size();
        vector<int> ans(size);
        stack<int> stk;
        for(int i = size - 1; i >= 0; i--){
            int h = heights[i];
            while(!stk.empty() && h >= stk.top()){
                ans[i] ++;
                stk.pop();
            }
            if(!stk.empty()){
                ans[i] ++;
            }
            stk.push(h);
        }
        return ans;
    }
};

int main(){

    return 0;
}