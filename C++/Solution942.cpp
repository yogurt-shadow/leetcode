#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class Solution942 {
public:
    vector<int> diStringMatch(string s) {
        int N = s.length();
        vector<int> ans(N + 1);
        int low = 0, high = N;
        for(int i = 0; i < N; i++){
            if(s[i] == 'I'){
                ans[i] = low;
                low ++;
            }
            else{
                ans[i] = high;
                high --;
            }
        }
        ans[N] = low;
        return ans;
    }
};