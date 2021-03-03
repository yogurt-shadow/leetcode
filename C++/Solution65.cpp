#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Autostate{
public:
    string state;
    unordered_map<string, vector<string>> map = {
        {"start", {"sign", "integer", "dot_no_front", "end", "end"}},
        {"sign", {"end", "integer", "dot_no_front", "end", "end"}},
        {"integer", {"end", "integer", "dot_front", "exp", "end"}},
        {"dot_no_front", {"end", "decimal", "end", "end", "end"}}, 
        {"dot_front", {"end", "decimal", "end", "exp", "end"}},
        {"decimal", {"end", "decimal", "end", "exp", "end"}},
        {"exp", {"esign", "einteger", "end", "end", "end"}},
        {"esign", {"end", "einteger", "end", "end", "end"}},
        {"einteger", {"end", "einteger", "end", "end", "end"}},
        {"end", {"end", "end", "end", "end", "end"}}
    };
    

    int getindex(char x){
        if(x == '+' || x == '-'){
            return 0;
        }
        if(x >= '0' && x <= '9'){
            return 1;
        }
        if(x == '.'){
            return 2;
        }
        if(x == 'e' || x == 'E'){
            return 3;
        }
        return 4;
    }


    Autostate(){
        state = "start";
    }

    void update(char x){
        state = map[state][getindex(x)];
    }
};

class Solution65 {
public:
    bool isNumber(string s) {
        Autostate ss;
        for(int i = 0; i < s.length(); i++){
            ss.update(s[i]);
        }
        return ss.state == "dot_front" || ss.state == "integer" || ss.state == "decimal" || ss.state == "einteger";
    }
};