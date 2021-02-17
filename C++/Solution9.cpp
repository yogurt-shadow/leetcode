#include<iostream>
#include<vector>

using namespace std;

class Solution9 {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }
        return x == reverse(x);
    }

    int reverse(int x){
        long result = 0;
        while(x > 0){
            result = 10 * result + x % 10;
            x = x / 10;
        }
        if(result > INT_MAX){
            return -1;
        }
        return result;
    }
};

int main(){
    Solution9 s;
    int x = INT_MAX;
    cout << s.isPalindrome(x);
    return 0;
}