#include<iostream>
#include<vector>

using namespace std;

class Solution16_7 {
public:
    int maximum(int a, int b) {
        long k = (((long)a - (long)b) >> 63) & 1;
        return b * k + a * (k ^ 1);
    }
};

int main(){
    Solution16_7 s;
    cout << s.maximum(2147483647, -2147483648);
    return 0;
}