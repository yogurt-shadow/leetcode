#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<stack>
#include<cstring>

using namespace std;
using ll = long long;

class Solution1 {
public:
    int sumBase(int n, int k) {
        int cur = k;
        int sum = 0;
        while(n){
            sum += n % cur;
            n = n / cur;
        }
        return sum;
    }
};

int main(){
    return 0;
}