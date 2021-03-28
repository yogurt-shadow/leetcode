#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution5713 {
public:
    int numDifferentIntegers(string word) {
        word = word + "a";
        unordered_set<string> set;
        string x = "";
        int res = 0;
        bool put = true;
        for(int i  = 0; i < word.length(); i++){
            if(word[i] >= '0' && word[i] <= '9'){
                put = false;
                x += word[i];
            }
            else{
                if(!put){
                    put = true;
                    x = removezero(x);
                    if(set.count(x) == 0){
                        //cout << x << endl;
                        set.insert(x);
                        res++;
                    }
                }
                x = "";
            }
        }
        //cout << set.count(34) << endl;
        //cout << removezero("010") << endl;
        return res;
    }
    
    string removezero(string str){
        int index = 0;
        while(index < str.length() - 1){
            if(str[index] == '0'){
                index++;
            }
            else{
                break;
            }
        }
        return str.substr(index, str.length() - index + 1);
    }
};