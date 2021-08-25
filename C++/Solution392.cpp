#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class Solution392 {
public:
    bool isSubsequence(string s, string t) {
        int index1 = 0, index2 = 0;
        while(index1 < s.length() && index2 < t.length()){
            if(t[index2] == s[index1]){
                index1 ++;
            }
            index2 ++;
        }
        return index1 == s.length();
    }
};