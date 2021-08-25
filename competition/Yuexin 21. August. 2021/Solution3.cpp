#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<math.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class Solution3 {
public:
    int getKthNum(int k){
        if (k <= 9){
            return k;
        }
        vector<int> digit = {1, 10, 190, 2890, 38890, 488890, 5888890, 68888890, 788888890};
        auto index = lower_bound(digit.begin(), digit.end(), k);
        if (index != digit.end() && *index == k){
            return 1;
        }
        int last = *(index - 1);
        int num = (index - digit.begin()); //shuwei
        int dep = k - last;
        int number = dep / num;
        int cur_num = number + pow(10, num - 1);
        int left = dep % num;
        /*
        cout << dep << endl;
        cout << num << endl;
        cout << num - 1 - left << endl;
        cout << cur_num << endl;
        */
        return find(cur_num, num - 1 - left);
    }

    int find(int x, int right){
        while (right){
            x /= 10;
            right--;
        }
        return x % 10;
    }
};

int main(){
    Solution3 s;
    //cout << s.getKthNum(20) << endl;
    ll x = 68888890 + 8 * 89999999 + 8;
    cout << x << endl;
    cout << INT_MAX << endl;
    return 0;
}