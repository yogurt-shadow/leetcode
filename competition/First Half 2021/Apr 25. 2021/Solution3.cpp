#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<stack>
#include<cstring>

using namespace std;
using ll = long long;

class Solution3 {
public:
    int longestBeautifulSubstring(string word) {
        int len = 0;
        int left = 0;
        int right = 0;
        char yy = ' ';
        while(right < word.length()){
            char cur = word[right];
            //cout << cur << yy << left << endl;
            if(yy == ' '){
                
                if(index(cur) == 1){
                    yy = 'a';
                }
                else if(index(cur) > 1){
                    left = right + 1;
                }
            }
            else{
                
                if(index(cur) == index(yy) + 1){
                    
                    yy = cur;
                    if(yy == 'u'){
                        len = max(len, right - left + 1);
                    }
                }
                else if(index(cur) < 1 || index(cur) == index(yy)){
                    if(right == 4){
                    cout << "dqwd2" << endl;
                }
                    if(yy == 'u'){
                        len = max(len, right - left + 1);
                    }
                }
                else{
                    yy = ' ';
                    if(cur == 'a'){
                        left = right;
                        yy = 'a';
                    }
                    else{
                        left = right + 1;
                    }
                }
            }
            right ++;
        }
        return len;
    }

    int index(char x){
        switch(x){
            case 'a':
            return 1;
            case 'e':
            return 2;
            case 'i':
            return 3;
            case 'o':
            return 4;
            case 'u':
            return 5;
            default:
            return 0;
        }
        return -1;
    }
};

int main(){
    Solution3 s;
    cout << s.longestBeautifulSubstring("aaaaeiiiiouuu") << endl;
    return 0;
}