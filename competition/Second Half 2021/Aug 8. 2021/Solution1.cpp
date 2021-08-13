#include<iostream>
#include<vector>

using namespace std;

class Solution1 {
public:
    bool isPrefixString(string s, vector<string> &words)
    {
        string str = "";
        for (auto ele : words)
        {
            str += ele;
            if (str == s)
            {
                return true;
            }
            if (str.length() >= s.length())
            {
                return false;
            }
        }
        return false;
    }
};

int main(){
    
    return 0;
}
