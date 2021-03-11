#include<iostream>
#include<vector>

using namespace std;

class Solution1047 {
public:
    string removeDuplicates(string S) {
        string res = "";
        bool change = false;
        for(int i = 0; i < S.length(); i++){
            if(i + 1 < S.length() && S[i + 1] == S[i]){
                i = i + 1;
                change = true;
            }
            else{
                res += S[i];
            }
        }
        return change ? removeDuplicates(res) : res;
    }
};