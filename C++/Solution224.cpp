#include<iostream>
#include<vector>

using namespace std;

class Solution224 {
public:
    int calculate(string s) {
        int sign = 1;
        int res = 0;
        int number = 0;
        for(int i = 0; i < s.length();){
            if(s[i] >= '0' && s[i] <= '9'){
                number = 10 * number + (s[i] - '0');
                i++;
            }
            else if(s[i] == ' '){
                i++;
            }
            else if(s[i] == '+' || s[i] == '-'){
                res += sign * number;
                sign = (s[i] == '+') ? 1 : -1;
                number = 0;
                i++;
            }
            else if(s[i] == '('){
                i++;
                int copy = i;
                int ans = -1;
                while(i < s.length()){
                    if(s[i] == '('){
                        ans -= 1;
                    }
                    else if(s[i] == ')'){
                        ans += 1;
                        if(ans == 0){
                            break;
                        }
                    }
                    i++;
                }
                number = calculate(s.substr(copy, i - copy));
                i++;
            }
        }
        res += number * sign;
        return res;
    }
};