#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution17 {
public:
    unordered_map<char, vector<char>> map = {
            {'2', {'a', 'b', 'c'}}, {'3', {'d', 'e', 'f'}}, {'4', {'g', 'h', 'i'}}, 
            {'5', {'j', 'k', 'l'}}, {'6', {'m', 'n', 'o'}}, {'7', {'p', 'q', 'r', 's'}}, 
            {'8', {'t', 'u', 'v'}}, {'9', {'w', 'x', 'y', 'z'}}
        };

    vector<string> letterCombinations(string digits) {
        vector<string> result;
        put(result, "", digits, 0);
        return result;
    }
    void put(vector<string>& result, string cur, string str, int index){
        char digit = str[index];
        string copy = cur;
        for(auto ele: map[digit]){
            cur += ele;
            if(index == str.size() - 1){
                result.push_back(cur);
            }
            else{
                put(result, cur, str, index + 1);
            }
            cur = copy;
        }
    }
};