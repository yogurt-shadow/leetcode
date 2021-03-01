#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution58 {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        bool collect = false;
        for(int index = s.length() - 1; index >= 0; index--){
            if(s[index] != ' '){
                len++;
                collect = true;
            }
            else{
                if(collect){
                    return len;
                }
            }
        }
        return len;
    }
};