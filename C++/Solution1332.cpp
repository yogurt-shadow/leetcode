#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class Solution1332 {
public:
    int removePalindromeSub(string s) {
        if(s == "") return 0;
        if(palin(s)) return 1;
        return 2;
    }

    bool palin(string s){
        int left = 0, right = s.length() - 1;
        while(right > left){
            if(s[left] != s[right]){
                return false;
            }
            left ++;
            right --;
        }
        return true;
    }
};