#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<stack>
#include<cstring>

using namespace std;
using ll = long long;

class Solution4{
public:
    const int MOD = 1000000000 + 7;
    int quickmul(int x, int y){
        int res = 1, mul = x;
        while(y){
            if(y & 1){
                res = (ll) res * mul % MOD;
            }
            mul = (ll) mul * mul % MOD;
            y = y >> 1;
        }
        return res;
    }

    int makeStringSorted(string s){
        int n = s.length();
        vector<int> fac(n + 1), facinv(n + 1);
        fac[0] = 1;
        facinv[0] = 1;
        for(int i = 1; i < n; i++){
            fac[i] = (ll) fac[i - 1] * i % MOD;
            facinv[i] = quickmul(fac[i], MOD - 2);
        }
        vector<int> freq(26);
        for(auto ele: s){
            freq[ele - 'a']++;
        }
        int ans = 0;
        for(int i = 0; i < n - 1; i++){
            int rank = 0;
            for(int j = 0; j < s[i] - 'a'; j++){
                rank += freq[j];
            }
            int cur = (ll) rank * fac[n -i - 1] % MOD;
            for(int j = 0; j < 26; j++){
                cur = (ll) cur * facinv[freq[j]] % MOD;
            }
            ans = (ans + cur) % MOD;
            freq[s[i] - 'a']--;
        }
        return ans;
    }
};

int main(){
    Solution4 s;
    string x = "leetcodeleetcodeleetcode";
    cout << s.makeStringSorted(x) << endl;
    return 0;
}