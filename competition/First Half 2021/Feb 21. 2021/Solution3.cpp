#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

class Solution3 {
public:
    int magicTower(vector<int>& nums) {
        ll res = 0;
        for(auto ele: nums){
            res += ele;
        }
        if(res <= 0){
            return -1;
        }
        
    }
};