#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class Solution2 {
public:
    int adjustLevel(int cnt) {
        int ans = 0;
        for (int i = 1; i * i <= cnt; i++) {
            ans++;
        }
        return ans;
    }
};

int main(){

    
    return 0;
}