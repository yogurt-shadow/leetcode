#include<iostream>
#include<vector>

#include<stack>

using namespace std;

class Solution20 {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(int i = 0; i < s.length(); i++){
            char cur = s[i];
            if(cur == '(' || cur == '[' || cur == '{'){
                stk.push(cur);
            }
            else{
                if(cur == ')'){
                    if(stk.empty() || stk.top() != '('){
                        return false;
                    }
                    stk.pop();
                }
                if(cur == ']'){
                    if(stk.empty() || stk.top() != '['){
                        return false;
                    }
                    stk.pop();
                }
                if(cur == '}'){
                    if(stk.empty() || stk.top() != '{'){
                        return false;
                    }
                    stk.pop();
                }
            }
        }
        return stk.empty();        
    }
};