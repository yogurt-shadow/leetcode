#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

class Solution784 {
public:
    vector<string> letterCasePermutation(string s) {
        vector<int> index;
        for (int i = 0; i < s.length(); i++){
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')){
                index.push_back(i);
            }
        }
        int size = index.size();
        vector<string> ans;
        if (size == 0){
            ans.push_back(s);
            return ans;
        }
        for (int mask = 0; mask < (1 << size); mask++){
            string cur = s;
            for (int i = 0; i < size; i++){
                if ((mask & (1 << i))){
                    cur[index[i]] = lower(cur[index[i]]);
                }
                else{
                    cur[index[i]] = upper(cur[index[i]]);
                }
            }
            ans.push_back(cur);
        }
        return ans;
    }

    char lower(char x){
        if (x >= 'a' && x <= 'z'){
            return x;
        }
        int y = x - 'A';
        return 'a' + y;
    }

    char upper(char x){
        if (x >= 'A' && x <= 'Z'){
            return x;
        }
        int y = x - 'a';
        return 'A' + y;
    }
};

int main(){
    char x = 'a';
    cout << (char) ('A' + (x - 'a')) << endl;
    return 0;
}