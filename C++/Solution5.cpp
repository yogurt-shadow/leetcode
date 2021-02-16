#include<iostream>
#include<vector>

using namespace std;

class Solution5 {
public:
    string longestPalindrome(string s) {
        int start = 0;
        int end = 0;
        int maxlen = 1;
        int size = s.length();
        for(int center = 0; center < size; center++){
            int len = 1;
            while(center - len >= 0 && center + len < size && s[center - len] == s[center + len]){
                len += 1;
            }
            if(2 * len - 1 > maxlen){
                start = center - len + 1;
                end = center + len - 1;
                maxlen = end - start + 1;
            }
            int len2 = 0;
            while(center - len2 >= 0 && center + 1 + len2 < size && s[center - len2] == s[center + 1 + len2]){
                len2 += 1;
            }
            if(2 * len2 > maxlen){
                start = center - len2 + 1;
                end = center + len2;
                maxlen = 2 * len2;
            }
        }
         return s.substr(start, maxlen);
    }
};

int main(){
    Solution5 s;
    string a = "bb";
    cout << s.longestPalindrome(a);
    return 0;
}