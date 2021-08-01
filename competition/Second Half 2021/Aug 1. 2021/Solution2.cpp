#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>

using namespace std;
typedef pair<int, int> pii;

typedef long long ll;

class Solution2 {
public:
    long long numberOfWeeks(vector<int> &milestones) {
        ll sum = 0;
        int m = 0;
        for(auto ele: milestones){
            sum += ele;
            m = max(m, ele);
        }
        ll res = sum - m;
        return min(sum, res * 2 + 1);
    }
};

int main(){

    return 0;
}