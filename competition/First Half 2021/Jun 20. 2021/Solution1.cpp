#include<iostream>
#include<vector>
#include<string>

using namespace std;

typedef long long ll;

typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<vii> viii;

class Solution1 {
public:
    string largestOddNumber(string num)
    {
        for (int i = num.length() - 1; i >= 0; i--)
        {
            int cur = num[i] - '0';
            if (cur % 2 == 1)
            {
                return num.substr(0, i + 1);
            }
        }
        return "";
    }
};

int main(){
    
    return 0;
}