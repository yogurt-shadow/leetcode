#include<iostream>
#include<vector>

using namespace std;

class Solution14 {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int size = strs.size();
        if(size == 0){
            return "";
        }
        string result = "";
        for(int i = 0; i < strs[0].length(); i++){
            char cur2 = strs[0][i];
            for(int index = 1; index < size; index++){
                string cur = strs[index];
                if(cur.length() <= i || cur[i] != cur2){
                    return result;
                }
            }
            result += cur2;
        }
        return result;
    }
};