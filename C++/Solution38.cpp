#include<iostream>
#include<vector>

using namespace std;

class Solution38 {
public:
    string countAndSay(int n) {
        if(n == 1){
            return "1";
        }
        string str = countAndSay(n - 1);
        string result = "";
        int index = 0, number = 0;
        char cur = str[0];
        while(index < str.length()){
            if(str[index] == cur){
                index++;
                number++;
            }
            else{
                result += number + '0';
                result += cur;
                cur = str[index];
                number = 1;
                index++;
            }
        }
        result += number + '0';
        result += cur;
        return result;
    }
};