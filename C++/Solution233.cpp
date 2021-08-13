#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<stack>
using namespace std;

typedef long long ll;

class Solution233 {
public:
    int countDigitOne(int n) {
        ll cnt = 0, i = 1, num = n;
        while (num) {
            if (num % 10 == 0)
                cnt += (num / 10) * i; //个
            if (num % 10 == 1)
                cnt += (num / 10) * i + (n % i) + 1; //十
            if (num % 10 > 1)
                cnt += ceil(num / 10.0) * i;
            num /= 10;
            i *= 10;
        }
        return cnt;
    }
};