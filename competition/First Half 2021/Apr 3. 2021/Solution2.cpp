#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<stack>

using namespace std;

class Solution2{
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> vec1, vec2;
        string cur = "";
        for(int i = 0; i < sentence1.length(); i++){
            if(sentence1[i] == ' '){
                if(cur != ""){
                    vec1.push_back(cur);
                    cur = "";
                }
            }
            else{
                cur += sentence1[i];
            }
        }
        vec1.push_back(cur);
        cur = "";
        for(int i = 0; i < sentence2.length(); i++){
            if(sentence2[i] == ' '){
                if(cur != ""){
                    vec2.push_back(cur);
                    cur = "";
                }
            }
            else{
                cur += sentence2[i];
            }
        }
        vec2.push_back(cur);
        int size1 = vec1.size();
        int size2 = vec2.size();
        int index1 = 0;
        int index2 = 0;
        if(size1 > size2){
            for(; index1 < size2; index1++){
                if(vec1[index1] != vec2[index1]){
                    break;
                }
            }
            if(index1 == size2){
                return true;
            }
            int index = size1 - 1;
            for(int j = size2 - 1; j >= index1; j--){
                if(vec2[j] != vec1[index]){
                    return false;
                }
                index--;
            }
            return true;
        }
        else if(size1 < size2){
            for(; index1 < size1; index1++){
                if(vec1[index1] != vec2[index1]){
                    break;
                }
            }
            if(index1 == size1){
                return true;
            }
            int index = size2 - 1;
            for(int j = size1 - 1; j >= index1; j--){
                if(vec1[j] != vec2[index]){
                    return false;
                }
                index--;
            }
            return true;
        }
        else{
            for(int i = 0; i < size1; i++){
                if(vec1[i] != vec2[i]){
                    return false;
                }
            }
            return true;
        }
    }
};