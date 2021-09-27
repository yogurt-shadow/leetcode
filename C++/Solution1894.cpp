#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class Solution1894 {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = 0;
        for(auto ele: chalk){
            sum += ele;
        }
        k %= sum;
        for(int i = 0; i < chalk.size(); i++){
            if(k < chalk[i]){
                return i;
            }
            k -= chalk[i];
        }
        return -1;
    }
};