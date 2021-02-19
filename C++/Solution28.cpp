#include<iostream>
#include<vector>

using namespace std;

class Solution28 {
public:
    int strStr(string haystack, string needle) {
        if(needle.length() == 0){
            return 0;
        }
        vector<int> array;
        for(int i = 0; i < haystack.length(); i++){
            if(haystack[i] == needle[0]){
                array.push_back(i);
            }
        }
        for(auto index: array){
            if(index + needle.length() > haystack.length()){
                continue;
            }
            bool match = true;
            for(int i = index; i < index + needle.length(); i++){
                if(needle[i - index] != haystack[i]){
                    match = false;
                    break;
                }
            }
            if(match){
                return index;
            }
        }
        return -1;
    }
};