#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<map>
#include<math.h>

using namespace std;

class Solution1441 {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int cur = 1;
        int index = 0;
        while(index < target.size()){
            ans.push_back("Push");
            if(cur == target[index]){
                index++;
            }
            else{
                ans.push_back("Pop");
            }
            cur++;
        }
        return ans;
    }
};