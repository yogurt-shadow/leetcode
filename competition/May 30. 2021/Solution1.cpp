#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <string>

using ll = long long;

using namespace std;

class Solution1 {
public:
    string convert(string x)
    {
        string ans = "";
        for (auto ele : x)
        {
            ans = ans + (char)((ele - 'a') + '0');
        }
        return ans;
    }

    bool isSumEqual(string firstWord, string secondWord, string targetWord)
    {
        string s1 = convert(firstWord);
        string s2 = convert(secondWord);
        string s3 = convert(targetWord);
        //cout << s1 << " " << s2 << " " << s3 << endl;
        return stoi(s3) == stoi(s1) + stoi(s2);
    }
};