#include<iostream>
#include<vector>

using namespace std;

class Solution4 {
public:
    long long maxProduct(string s) {
        int n = s.size();
        vector<int> span(n);

        // manacher
        for (int i = 0, l = 0, r = -1; i < n; ++i) {
            span[i] = (i <= r ? min(span[l + r - i], r - i + 1) : 1);
            while (i - span[i] >= 0 && i + span[i] < n && s[i - span[i]] == s[i + span[i]]) {
                ++span[i];
            }
            if (i + span[i] - 1 > r) {
                l = i - span[i] + 1;
                r = i + span[i] - 1;
            }
        }

        vector<int> pre(n), suf(n);
        for (int i = 0; i < n; ++i){
            pre[i + span[i] - 1] = max(pre[i + span[i] - 1], span[i] * 2 - 1);
            suf[i - span[i] + 1] = max(suf[i - span[i] + 1], span[i] * 2 - 1);
        }

        for (int i = 1; i < n; ++i){
            pre[i] = max(pre[i], pre[i - 1]);
        }
        for (int i = n - 2; i >= 0; --i){
            pre[i] = max(pre[i], pre[i + 1] - 2);
        }
        for (int i = n - 2; i >= 0; --i){
            suf[i] = max(suf[i], suf[i + 1]);
        }
        for (int i = 1; i < n; ++i){
            suf[i] = max(suf[i], suf[i - 1] - 2);
        }

        long long ans = 0;
        for (int i = 0; i < n - 1; ++i){
            ans = max(ans, (long long)pre[i] * suf[i + 1]);
        }
        return ans;
    }
};

int main(){

    return 0;
}