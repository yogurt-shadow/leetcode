#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <queue>

using ll = long long;

using namespace std;
typedef vector<pair<int, int>> vii;

typedef pair<int, int> pii;

class Solution1 {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans(nums.size() * 2);
        for(int i = 0; i < nums.size(); i++){
            ans[i] = nums[i];
            ans[i + nums.size()] = nums[i];
        }
        return ans;
    }
};

int main(){
   
    
    return 0;
}