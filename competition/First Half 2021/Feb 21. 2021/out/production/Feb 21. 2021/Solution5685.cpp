#include<iostream>

using namespace std;

class Solution5685 {
public:
    string mergeAlternately(string word1, string word2) {
        string result = "";
        int size1 = word1.length(), size2 = word2.length();
        int index1 = 0, index2 = 0;
        while(index1 < size1 && index2 < size2){
            result += word1[index1];
            result += word2[index2];
            index1++;
            index2++;
        }
        if(index1 == size1){
            while(index2 < size2){
                result += word2[index2];
                index2++;
            }
        }
        else{
            while(index1 < size1){
                result += word1[index1];
                index1++;
            }
        }
        return result;
    }
};