#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class Solution1 {
public:
    int numOfStrings(vector<string> &patterns, string word){
        int ans = 0;
        for (auto str : patterns){
            if (contains(word, str)){
                ans++;
            }
        }
        return ans;
    }

    bool contains(string s1, string s2){
        for (int i = 0; i + s2.length() <= s1.length(); i++){
            if (s1.substr(i, s2.length()) == s2) return true;
        }
        return false;
    }
};

int main(){
    
    return 0;
}