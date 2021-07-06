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

class Solution3 {
public:
    const int MOD = 1e9 + 7;

    ll quickMul(int x, long long N)
    {
        ll ans = 1;
        // 贡献的初始值为 x
        ll x_contribute = x;
        // 在对 N 进行二进制拆分的同时计算答案
        while (N > 0)
        {
            if (N % 2 == 1)
            {
                // 如果 N 二进制表示的最低位为 1，那么需要计入贡献
                ans *= x_contribute;
                ans %= MOD;
                
            }
            // 将贡献不断地平方
            x_contribute *= x_contribute;
            x_contribute %= MOD;
            
            // 舍弃 N 二进制表示的最低位，这样我们每次只要判断最低位即可
            N /= 2;
        }
        return ans % MOD;
    }

    ll myPow(int x, ll n)
    {
        long long N = n;
        return N >= 0 ? quickMul(x, N) % MOD : 1.0 / quickMul(x, -N);
    }

    int countGoodNumbers(long long n)
    {
       if(n % 2 == 0){
           int x = 20;
           ll time = n / 2;
           return myPow(x, time) % MOD;
       }
       ll time = n / 2;
       int x = 20;
       return myPow(x, time) % MOD * 5 % MOD;
    }
};

int main(){
     return 0;
}