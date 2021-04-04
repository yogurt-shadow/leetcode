#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<stack>

using namespace std;

class Solution1{
public:
    bool squareIsWhite(string coordinates) {
        int x1 = coordinates[0] - 'a';
        int x2 = coordinates[1] - '1';
        int x = x1 + x2;
        if(x % 2){
            return true;
        }
        return false;
    }
};