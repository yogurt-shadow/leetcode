#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class Solution541 {
public:
    string reverseStr(string s, int k) {
        string ans;
        for(int i = 0; i < s.length(); i += 2 * k){
            if(s.length() - i <= k){
                ans += reverse(s.substr(i, s.length() - i));
            }
            else if(s.length() - i > k && s.length() - i <= 2 * k){
                ans += reverse(s.substr(i, k));
                ans += s.substr(i + k, s.length() - (i + k));
            }
            else{
                ans += reverse(s.substr(i, k));
                ans += s.substr(i + k, k);
            }
        }
        return ans;
    }

    string reverse(string s){
        string ans;
        for(auto ele: s){
            ans = ele + ans;
        }
        return ans;
    }
};

int main(){
    Solution541 s;
    string str = "abcdefg";
    cout << s.reverseStr(str, 2) << endl;
    return 0;
}