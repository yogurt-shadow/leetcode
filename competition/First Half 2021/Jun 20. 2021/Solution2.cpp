#include<iostream>
#include<vector>
#include<string>

using namespace std;

typedef long long ll;

typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<vii> viii;

class Solution2 {
public:
    int convert(string s)
    {
        string s1 = s.substr(0, 2);
        string s2 = s.substr(3, 2);
        string ss = s1 + s2;
        int cur = 0;
        for (auto ele : ss)
        {
            cur = 10 * cur + (ele - '0');
        }
        return cur;
    }

    int close1(int x)
    {
        int end = x % 100;
        int start = x / 100;
        if (end == 0)
        {
            return x;
        }
        if (end > 45)
        {
            return (start + 1) * 100;
        }
        if (end > 30 && end <= 45)
        {
            return start * 100 + 45;
        }
        if (end > 15 && end <= 30)
        {
            return start * 100 + 30;
        }

        return start * 100 + 15;
    }

    int close2(int x)
    {
        int end = x % 100;
        int start = x / 100;
        if (end == 0)
        {
            return x;
        }
        if (end >= 45)
        {
            return start * 100 + 45;
        }
        if (end >= 30 && end < 45)
        {
            return start * 100 + 30;
        }
        if (end >= 15 && end < 30)
        {
            return start * 100 + 15;
        }
        return start * 100;
    }

    int cal(int x1, int x2)
    {
        int ans = 0;
        while (x1 < x2)
        {
            ans++;
            x1 += 15;
            if (x1 % 100 == 60)
            {
                x1 = (x1 / 100 + 1) * 100;
            }
        }
        return ans;
    }

    int numberOfRounds(string startTime, string finishTime)
    {
        int start = convert(startTime), end = convert(finishTime);
        if (end < start)
        {
            end += 2400;
        }
        int x1 = close1(start), x2 = close2(end);
        //cout << x1 << x2 << endl;
        return cal(x1, x2);
    }
};

int main(){
    
    return 0;
}