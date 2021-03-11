#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution227 {
public:
    int calculate(string s) {
        int number = 0;
        char presign = '+';
        stack<int> stk;
        for(int i = 0; i < s.length(); i++){
            if(s[i] >= '0' && s[i] <= '9'){
                number = 10 * number + (s[i] - '0');
            }
            if(s[i] == ' ' && i != s.length() - 1){
                continue;
            }
            if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || i == s.length() - 1){
                int cur = stk.empty() ? 0 : stk.top();
                switch(presign){
                    case '+':
                    stk.push(number);
                    break;

                    case '-':
                    stk.push(-number);
                    break;

                    case '*':
                    stk.pop();
                    stk.push(cur * number);
                    break;

                    case '/':
                    stk.pop();
                    stk.push(cur / number);
                    break;

                    default:
                    break;
                }
                number = 0;
                presign = s[i];
            }
        }
        int res = 0;
        while(!stk.empty()){
            res += stk.top();
            stk.pop();
        }
        return res;
    }
};