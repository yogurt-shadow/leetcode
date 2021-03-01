#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution50 {
public:
    double myPow(double x, int n) {
        if(n == INT_MIN){
            int half = n / 2;
            double next = myPow2(x, -half);
            return 1.0 / (next * next);
        }
        return n > 0 ? myPow2(x, n) : 1.0 / myPow2(x, -n);
    }

    double myPow2(double x, int n){
        if(n == 0){
            return 1;
        }
        double next = myPow2(x, n / 2);
        return n % 2 == 1 ? next * next * x : next * next;
    }
};