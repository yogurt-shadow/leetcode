#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<stack>

using namespace std;
typedef long long ll;

class Solution633 {
public:
    bool judgeSquareSum(int c) {
        ll a = 0, b = (int) sqrt(c);
        while(b > a){
            ll cur = a*a + b*b;
            if(cur == c){
                return true;
            }
            if(cur > c){
                b --;
            }
            else{
                a ++;
            }
        }
        return a * a * 2 == c;
    }
};