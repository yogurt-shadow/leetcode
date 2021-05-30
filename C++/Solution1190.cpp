#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<stack>

using namespace std;
typedef long long ll;

class Solution1190 {
public:
    string reverseParentheses(string s) {
        string ans = "";
        stack<string> stk;
        for(auto ele: s){
            if(ele == '('){
                stk.push(ans);
                ans = "";
            }
            else if(ele == ')'){
                reverse(ans.begin(), ans.end());
                ans = stk.top() + ans;
                stk.pop();
            }
            else{
                ans += ele;
            }
        }
        return ans;
    }
};