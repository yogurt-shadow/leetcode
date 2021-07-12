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

class Solution3 {
public:
    bool sumGame(string num) {
        int sum = 0, cnt = 0;
        for(int i = 0; i < num.size() / 2; i++){
            if(num[i] == '?'){
                cnt ++;
            }
            else{
                sum += (num[i] - '0');
            }
        }
        for(int i = num.size() / 2; i < num.size(); i++){
            if(num[i] == '?'){
                cnt --;
            }
            else{
                sum -= (num[i] - '0');
            }
        }
        if((sum == 0 && cnt == 0) || (cnt % 2 == 0 && abs(sum) == abs(cnt) / 2 * 9)){
            return false;
        }
        return true;
    }
};

int main(){
   
    
    return 0;
}