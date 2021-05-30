#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<stack>
#include<cstring>

using namespace std;
using ll = long long;

class Solution3{
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int> res(nums.size());
        int cur = 0;
        for(int i = 0; i < nums.size(); i++){
            cur = cur ^ nums[i];
            int k = 0;
            for(int j = 0; j < maximumBit; j++){
                int digit = (1 << j) & cur;
                if(!digit){
                    k = k ^ (1 << j);
                }
            }
            res[nums.size() - 1 - i] = k;
        }
        return res;
    }
};

int main(){
    cout << (1 << 2) << endl;
    return 0;
}