#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>

using namespace std;

class Solution5714 {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> map;
        for(auto ele: knowledge){
            map[ele[0]] = ele[1];
        }
        string res = "";
        int index = 0;
        while(index < s.length()){
            if(s[index] == '('){
                int x = index + 1;
                while(s[x] != ')'){
                    x++;
                }
                string mid = s.substr(index + 1, x - index - 1);
                if(map.count(mid) == 0){
                    res += "?";
                }
                else{
                    res += map[mid];
                }
                index = x + 1;
            }
            else{
                res += s[index];
                index++;
            }
        }
        return res;
    }
};