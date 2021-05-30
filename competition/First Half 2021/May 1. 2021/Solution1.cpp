#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>

using namespace std;

typedef long long ll;

class Solution1 {
public:
    string replaceDigits(string s) {
        string res = "";

        for(int i = 0; i < s.length(); i++){
            if(i % 2 == 0){
                res += s[i];
            }
            else{
                res += shift(s[i - 1], s[i]);
            }
        }
        return res;
    }

    char shift(char x, char y){
        int yy = y - '0';
        return (char) ((int) x + yy);
    }
};

int main(){
    char x = 'a';
    cout << (char) ((int) x + 1) << endl;
    return 0;
}