#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<stack>
#include<cstring>

using namespace std;
using ll = long long;

class Solution4{
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int ans1 = 0;
        for(auto ele: arr1){
            ans1 ^= ele; 
        }
        int ans2 = 0;
        for(auto ele: arr2){
            ans2 ^= ele;
        }
        return ans1 & ans2;
    }
};

int main(){
    cout << ((1 ^ 2 ^ 3) & (6 ^ 5)) << endl;
    return 0;
}