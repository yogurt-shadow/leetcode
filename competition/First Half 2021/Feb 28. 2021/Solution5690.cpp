#include<iostream>
#include<vector>

#include<algorithm>

using namespace std;

class Solution5690 {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int res = INT_MAX;
        int diff = INT_MAX;
        int size = toppingCosts.size();
        for(auto ele: baseCosts){
            for(int i = 0; i < (1 << size); i++){
                for(int j = i; j < (1 << size); j++){
                    int cur = ele;
                    for(int k = 0; k < size; k++){
                        if((i & (1 << k)) != 0){
                            cur += toppingCosts[k];
                        }
                        if((j & (1 << k)) != 0){
                            cur += toppingCosts[k];
                        }
                    }
                    if(abs(cur - target) == 0){
                            return target;
                        }
                        if(abs(cur - target) < diff){
                            diff = abs(cur - target);
                            res = cur;
                        }
                        else if(abs(cur - target) == diff){
                            res = min(res, cur);
                        }
                }
            }
        }
        return res;
    }
};

int main(){
    Solution5690 s;
    vector<int> test1 = {2, 3};
    vector<int> test2 = {4, 5, 100};
    cout << s.closestCost(test1, test2, 18);
    return 0;
}