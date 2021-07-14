#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<queue>

using namespace std;

typedef long long ll;

class Solution1688 {
public:
    int numberOfMatches(int n) {
        int ans = 0;
        while(n > 1){
            if(n % 2 == 1){
                ans += (n - 1) / 2;
                n = (n - 1) / 2 + 1;
            }
            else{
                ans += n / 2;
                n = n / 2;
            }
        }
        return ans;
    }
};