#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<string>
#include<stack>

using namespace std;
typedef long long ll;

class Solution213 {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if(size == 1){
            return nums[0];
        }
        if(size == 2){
            return max(nums[0], nums[1]);
        }
        vector<int> dp1(size - 1), dp2(size - 1);
        dp1[0] = nums[0];
        dp1[1] = max(nums[0], nums[1]);
        for(int i = 2; i + 1 < size; i++){
            dp1[i] = max(dp1[i - 2] + nums[i], dp1[i - 1]);
        }
        dp2[0] = nums[1];
        dp2[1] = max(nums[1], nums[2]);
        for(int i = 3; i < size; i++){
            dp2[i - 1] = max(nums[i] + dp2[i - 3], dp2[i - 2]);
        }
        return max(dp1[size - 2], dp2[size - 2]);
    }
};

int main(){
    Solution213 s;
    vector<int> input = {1, 7, 9, 2};
    cout << s.rob(input) << endl;
    return 0;
}