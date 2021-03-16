#include<iostream>
#include<vector>

using namespace std;

class Solution331 {
public:
    bool isValidSerialization(string preorder) {
        int space = 1;
        for(auto ele: split(preorder, ',')){
            space--;
            if(space < 0){
                return false;
            }
            if(ele != "#"){
                space += 2;
            }
        }
        return space == 0;
    }

    vector<string> split(string str, char x){
        vector<string> res;
        int i = 0;
        while(i < str.length()){
            while(i < str.length() && str[i] == x){
                i++;
            }
            if(i == str.length()){
                break;
            }
            int j = i;
            while(j < str.length() && str[j] != x){
                j++;
            }
            j--;
            res.push_back(str.substr(i, j - i + 1));
            i = j + 1;
        }
        return res;
    }
};