#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <string>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class Solution {
public:
    string thousandSeparator(int n) {
        string ans;
        while(n >= 1000){
            int cur = n % 1000;
            n = n / 1000;
            ans = "." + convert1(cur) + ans;
        }
        ans = convert2(n) + ans;
        return ans;
    }

    string convert1(int x){
        string s;
        while(x){
            char cur = x % 10 + '0';
            s = cur + s;
            x = x / 10;
        }
        while(s.length() < 3){
            s = '0' + s;
        }
        return s;
    }

    string convert2(int x){
        string s;
        if(x == 0){
            return "0";
        }
        while (x){
            char cur = x % 10 + '0';
            s = cur + s;
            x = x / 10;
        }
        return s;
    }
};