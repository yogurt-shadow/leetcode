#include<iostream>
using namespace std;

class Solution5697 {
public:
    bool checkOnesSegment(string s) {
        bool start = false;
        bool com = false;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '1'){
                if(com){
                    return false;
                }
                start = true;
            }
            else{
                if(start){
                    com = true;
                }
            }
        }
        return true;
    }
};