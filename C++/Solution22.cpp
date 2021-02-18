#include<iostream>
#include<vector>

using namespace std;

class Solution22 {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string cur = "";
        put(result, cur, 0, 2 * n);
        return result;
    }

    bool isvalid(string str){
        int count = 0;
        for(int i = 0; i < str.length(); i++){
            if(str[i] == '('){
                count++;
            }
            if(str[i] == ')'){
                count--;
                if(count < 0){
                    return false;
                }
            }
        }
        return count == 0;
    }

    void put(vector<string>& result, string cur, int index, int length){
        string copy = cur;
        char choice[] = {'(', ')'};
        for(int i = 0; i < 2; i++){
            cur += choice[i];
            if(index == length - 1){
                if(isvalid(cur)){
                    result.push_back(cur);
                }
            }
            else{
                put(result, cur, index + 1, length);
            }
            cur = copy;
        }
    }
};