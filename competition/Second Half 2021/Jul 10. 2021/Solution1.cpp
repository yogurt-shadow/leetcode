#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <queue>

using ll = long long;

using namespace std;
typedef vector<pair<int, int>> vii;

typedef pair<int, int> pii;

class Solution1 {
public:
    int countTriples(int n) {
        int res = 0;
        for(int a = 1; a <= n; a++){
            for(int b = 1; b <= n; b++){
                for(int c = 1; c <= n; c++){
                    if(a * a + b * b == c * c){
                        res ++;
                    }
                }
            }
        }
        return res;
    }
};

int main(){
   
    
    return 0;
}