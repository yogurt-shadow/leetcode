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

class Solution2 {
public:
    int countPalindromicSubsequence(string s) {
        int res = 0;
        for(char x = 'a'; x <= 'z'; x++){
            for(char y = 'a'; y <= 'z'; y++){
                int cur = 0;
                for(int i = 0; i < s.length(); i++){
                    char z = s[i];
                    if(cur == 3){
                        continue;
                    }
                    if(cur == 0 && z == x){
                        cur ++;
                    }
                    else if(cur == 1 && z == y){
                        cur ++;
                    }
                    else if(cur == 2 && z == x){
                        res ++;
                        cur ++;
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