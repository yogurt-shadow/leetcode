#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

class Solution917 {
public:
    string reverseOnlyLetters(string s) {
        string ans = "";
        stack<char> stk;
        for(int i = 0; i < s.length(); i++){
            if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')){
                stk.push(s[i]);
            }
        }
        for(int i = 0; i < s.length(); i++){
            if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')){
                ans += stk.top();
                stk.pop();
            }
            else{
                ans += s[i];
            }
        }
        return ans;
    }
};