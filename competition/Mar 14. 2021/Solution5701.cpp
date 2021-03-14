#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution5701 {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1 == s2){
            return true;
        }
        for(int i = 0; i < s2.length(); i++){
            for(int j = i + 1; j < s2.length(); j++){
                string s3 = s2;
                char copy = s3[i];
                s3[i] = s3[j];
                s3[j] = copy;
                if(s3 == s1){
                    return true;
                }
            }
        }
        return false;
    }
};