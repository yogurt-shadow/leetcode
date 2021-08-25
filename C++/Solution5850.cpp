#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<map>
#include<math.h>

using namespace std;


class Solution5850x {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return __gcd(nums[0], nums.back());
    }
};

int main(){
    cout << __gcd(12, 24) << endl;
    return 0;
}