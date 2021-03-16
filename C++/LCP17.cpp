#include<iostream>
#include<vector>

#include<unordered_map>

using namespace std;

class LCP17 {
public:
    int calculate(string s) {
        int x = 1, y = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'A'){
                x = 2 * x + y;
            }
            else if(s[i] == 'B'){
                y = 2 * y + x;
            }
        }
        return x + y;
    }
};