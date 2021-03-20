#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<unordered_map>

using namespace std;

class Solution150 {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(string ele: tokens){
            if(ele == "+"){
                int x = stk.top();
                stk.pop();
                int y = stk.top();
                stk.pop();
                stk.push(x + y);
            }
            else if(ele == "-"){
                int x = stk.top();
                stk.pop();
                int y = stk.top();
                stk.pop();
                stk.push(y - x);
            }
            else if(ele == "*"){
                int x = stk.top();
                stk.pop();
                int y = stk.top();
                stk.pop();
                stk.push(x * y);
            }
            else if(ele == "/"){
                int x = stk.top();
                stk.pop();
                int y = stk.top();
                stk.pop();
                stk.push(y / x);
            }
            else{
                stk.push(stoi(ele));
            }
        }
        return stk.top();
    }
};