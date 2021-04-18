#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<stack>
#include<cstring>

using namespace std;
using ll = long long;

class Solution2{
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int res = 0;
        for(int i = 0; i < costs.size(); i++){
            if(coins >= costs[i]){
                res++;
                coins -= costs[i];
            }
            else{
                break;
            }
        }
        return res;
    }
};
int main(){

    return 0;
}