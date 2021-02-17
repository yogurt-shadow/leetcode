#include<iostream>
#include<vector>

#include<unordered_map>

using namespace std;

/**        space     + / -     digit    other
 *  start   start      sign     number    end 
 *   sign    end       end      number    end
 *   number  end       end      number    end
 *   end     end       end       end      end
 * */
class Automation{
public:
    long long result = 0;
    unordered_map<string, vector<string>> map = {
        {"start", {"start", "sign", "number", "end"}},
        {"sign", {"end", "end", "number", "end"}},
        {"number", {"end", "end", "number", "end"}}, 
        {"end", {"end", "end", "end", "end"}}
    };
    int sign = 1;
    string state = "start";

    int index(char x){
        if(x == ' '){
            return 0;
        }
        if(x == '+' || x == '-'){
            return 1;
        }
        if(x >= '0' && x <= '9'){
            return 2;
        }
        return 3;
    }

    void update(char x){
        state = map[state][index(x)];
        if(state == "number"){
            result = 10 * result + x - '0';
            result = sign == 1 ? min(result, (long long) INT_MAX) :min(result, - (long long) INT_MIN);
        }
        if(state == "sign"){
            sign = x == '+' ? 1 : -1;
        }
    }
};

class Solution8 {
public:
    int myAtoi(string s) {
        Automation automation;
        for(int i = 0; i < s.length(); i++){
            automation.update(s[i]);
        }
        return automation.sign * automation.result;
    }
};

int main(){
    Solution8 s;
    string s1 = "4193 with words";
    string s2 = "-91283472332";
    cout << s.myAtoi(s1) << endl;
    cout << s.myAtoi(s2) << endl;
    return 0;
}