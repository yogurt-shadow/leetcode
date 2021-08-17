#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;


class Solution526 {
public:
    int ans = 0;
    vector<int> vec;

    int countArrangement(int n) {
        vec.resize(n + 1, 0);
        dfs(n, 1);
        return ans;
    }

    void dfs(int n, int index){
        if(index > n){
            ans ++;
            return;
        }
        for(int i = 1; i <= n; i++){
            if(vec[i] == 1){
                continue;
            }
            if(i % index == 0 || index % i == 0){
                vec[i] = 1;
                dfs(n, index + 1);
                vec[i] = 0;
            }
        }
    }
};
