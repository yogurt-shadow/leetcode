#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;

typedef long long ll;

class Solution446 {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int sum = 0;
        int size = nums.size();
        vector<unordered_map<ll, int>> two(size), three(size);
        for(int i = 0; i < size; i++){
            for(int j = 0; j < i; j++){
                ll d = (ll) nums[i] - (ll) nums[j];
                three[i][d] += two[j][d];
                two[i][d] += two[j][d] + 1;
            }
        }
        for(int i = 0; i < size; i++){
            for(auto ele: three[i]){
                sum += ele.second;
            }
        }
        return sum;
    }
};