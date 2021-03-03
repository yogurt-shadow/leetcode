#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution68 {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        if(words.size() == 0){
            return vector<string>(0);
        }
        int index = 0;
        int len = words[index].length();
        index++;
        while(index < words.size()){
            len++;
            len += words[index].length();
            if(len > maxWidth){
                break;
            }
            index++;
        }
        if(index == words.size()){
            vector<string> res;
            string str = "";
            str += words[0];
            for(int i = 1; i < words.size(); i++){
                str += " ";
                str += words[i];
            }
            while(str.length() < maxWidth){
                str += " ";
            }
            res.push_back(str);
            return res;
        }
        index--;
        vector<string> res;
        string str = "";
        if(index == 0){
            str += words[0];
            while(str.length() < maxWidth){
                str += " ";
            }
        }
        else{
            int sum = 0;
            for(int i = 0; i <= index; i++){
                sum += words[i].length();
            }
            int space = maxWidth - sum;
            int aver = space / index;
            int left = space - aver * index;
            str += words[0];
            for(int i = 1; i <= index; i++){
                for(int j = 0; j < aver; j++){
                    str += " ";
                }
                if(left > 0){
                    str += " ";
                    left--;
                }
                str += words[i];
            }
        }
        res.push_back(str);
        vector<string> copy(words.begin() + index + 1, words.end());
        auto other = fullJustify(copy, maxWidth);
        for(string ele: other){
            res.push_back(ele);
        }
        return res;
    }
};