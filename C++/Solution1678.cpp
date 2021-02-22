#include<iostream>
#include<vector>

using namespace std;

class Solution1678 {
public:
    string interpret(string command) {
        string result = "";
        int index = 0;
        while(index < command.length()){
            char cur = command[index];
            switch(cur){
                case 'G':
                result += "G";
                index++;
                break;

                case '(':
                if(command[index + 1] == ')'){
                    result += "o";
                    index = index + 2;
                }
                else{
                    result += "al";
                    index = index + 4;
                }
                break;

                default:
                break;
            }
        }
        return result;
    }
};