#include<iostream>
#include<vector>

using namespace std;

class Solution13 {
public:
    int romanToInt(string s) {
        vector<pair<int, string>> map = {
            {1, "I"}, {4, "IV"}, {5, "V"}, {9, "IX"}, {10, "X"}, {40, "XL"}, {50, "L"}, {90, "XC"}, 
            {100, "C"}, {400, "CD"}, {500, "D"}, {900, "CM"}, {1000, "M"}
        };
        int result = 0;
        int size = map.size();
        int i = 0;
        while(i < s.length()){
            for(int index = size - 1; index >= 0; index--){
                auto cur = map[index];
                if(cur.second.length() == 2){
                    if(i + 1 < s.length() && s.substr(i, 2) == cur.second){
                        result += cur.first;
                        i = i + 2;
                        break;
                    }
                }
                else{
                    if(s[i] == cur.second[0]){
                        result += cur.first;
                        i++;
                        break;
                    }
                }
            }
        }
        return result;
    }
};