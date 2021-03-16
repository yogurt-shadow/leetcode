#include<iostream>
#include<vector>
#include<algorithm>

#include<unordered_map>

using namespace std;

class LCP18 {
public:
    int breakfastNumber(vector<int>& staple, vector<int>& drinks, int x) {
        const int MOD = 1000000000 + 7;
        long long res = 0;
        sort(staple.begin(), staple.end());
        sort(drinks.begin(), drinks.end());
        int j = drinks.size() - 1;
        for(int i = 0; i < staple.size(); i++){
            if(staple[i] >= x){
                break;
            }
            while(j >= 0 && drinks[j] + staple[i] > x){
                j--;
            }
            res += (j + 1) % MOD;
            res = res % MOD;
        }
        return res;
    }
};