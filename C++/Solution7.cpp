#include<iostream>
#include<vector>

using namespace std;

class Solution7 {
public:
    int reverse(int x) {
        if(x == INT_MAX || x == INT_MIN){
            return 0;
        }
        if(x < 0){
            return -reverse(-x);
        }
        long result = 0;
        while(x != 0){
            result  = result * 10 + x % 10;
            x = x / 10;
        }
        if(result >= INT_MAX){
            return 0;
        }
        return int(result);
    }
};

int main(){
    Solution7 s;
    cout << s.reverse(123);
}