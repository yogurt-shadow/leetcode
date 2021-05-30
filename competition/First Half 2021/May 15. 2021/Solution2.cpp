#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

typedef long long ll;

class Solution2
{
public:
    vector<int> memLeak(int memory1, int memory2)
    {
        int cur = 1;
        while (memory1 >= cur || memory2 >= cur)
        {
            if (memory1 >= memory2)
            {
                memory1 -= cur;
                cur++;
            }
            else
            {
                memory2 -= cur;
                cur++;
            }
            //cout << cur << endl;
        }
        return {cur, memory1, memory2};
    }
};

int main(){

    return 0;
}