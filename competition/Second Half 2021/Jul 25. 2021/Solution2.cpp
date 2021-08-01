#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <map>

using ll = long long;

using namespace std;
typedef vector<pair<int, int>> vii;

typedef pair<int, int> pii;

class Solution2 {
public:
    string maximumNumber(string num, vector<int> &change)
    {
        int left = 0, right = 0;
        string ans = num;
        while (left < num.length())
        {
            int cur = num[left] - '0';
            if (change[cur] <= cur)
            {
                left++;
                continue;
            }
            right = left + 1;
            while (right < num.length())
            {
                //cout << right << endl;
                int cur2 = num[right] - '0';
                //cout << cur2 << change[cur2] << endl;
                if (change[cur2] < cur2)
                {
                    break;
                }
                right++;
            }
            string copy = num;
            for (int index = left; index < right; index++)
            {
                copy[index] = change[num[index] - '0'] + '0';
            }
            return copy;
        }
        return num;
    }
};

int main(){
    string asd = "dsad";
    asd[0] = 'a';
    cout << asd << endl;
    return 0;
}