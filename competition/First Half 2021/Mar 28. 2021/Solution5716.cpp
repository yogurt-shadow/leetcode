#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>

using namespace std;

typedef long long ll;

class Solution5716 {
public:
    const int MOD = 1000000000 + 7;
    int maxNiceDivisors(int primeFactors) {
        if(primeFactors <= 3){
            return primeFactors;
        }
        ll res = 0;
        int divide = primeFactors / 3;
        int left = primeFactors % 3;
        if(left == 0){
            res = myPow(3, divide);
        }
        else if(left == 1){
            res = myPow(3, divide - 1) * 4;
        }
        else{
            res = myPow(3, divide) * 2;
        }
        return res % MOD;
    }

    ll myPow(int x, int y){
        if(y == 0){
            return 1;
        }
        if(y == 1){
            return x % MOD;
        }
        ll temp = myPow(x, y / 2) % MOD;
        return y % 2 == 0 ? (temp * temp) % MOD : (x * temp * temp) % MOD;
    }
};