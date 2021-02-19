#include<iostream>
#include<vector>

using namespace std;

class Solution29 {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 1){
            return dividend;
        }
        if(divisor == -1){
            return dividend == INT_MIN ? INT_MAX : -dividend;
        }
        int sign = 1;
        if((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)){
            sign = -1;
        }
        long a = abs((long) dividend);
        long b = abs((long) divisor);
        long result = div(a, b);
        if(sign == 1){
            return result >= INT_MAX ? INT_MAX : result;
        }
        return -result;
    }

    long div(long a, long b){
        if(a < b){
            return 0;
        }
        long count = 1;
        long copy = b;
        while(copy * 2 <= a){
            copy = copy * 2;
            count = count * 2;
        }
        return count + div(a - copy, b);
    }
};
int main(){
    Solution29 s;
    cout << s.divide(10, 3);
}