#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class Solution2 {
public:
    vector<int> rearrangeArray(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans(nums.size(), 0);
        int j = 0;
        for(int index = 0; index < nums.size(); index += 2){
            ans[index] = nums[j];
            j ++;
        }
        for(int index = 1; index < nums.size(); index += 2){
            ans[index] = nums[j];
            j ++;
        }
        return ans;
    }
};

int main(){
    
    return 0;
}