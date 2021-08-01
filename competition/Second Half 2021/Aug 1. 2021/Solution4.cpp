#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

class Solution4 {
public:
    const int MOD = 1e9 + 7;

    int countSpecialSubsequences(vector<int> &nums){
        ll one = 0, two = 0, zero = 0;
        for(auto ele: nums){
            if(ele == 0){
                zero += zero + 1;
                zero %= MOD;
            }
            else if(ele == 1){
                one += zero + one;
                one %= MOD;
            }
            else{
                two += one + two;
                two %= MOD;
            }
        }
        return two;
    }
};

int main(){

    return 0;
}