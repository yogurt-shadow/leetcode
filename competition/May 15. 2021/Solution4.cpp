#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;

class Solution4{
public:
    int sumOfFlooredPairs(vector<int> &nums)
    {
        vector<long long> arr(200010, 0);
        vector<long long> sum(200010, 0);
        int maxV = 0;
        long long ret = 0;
        for (auto it : nums)
        {
            maxV = max(maxV, it);
            arr[it]++;
        }
        for (int i = 1; i <= maxV * 2; ++i)
        {
            sum[i] = sum[i - 1] + arr[i];
        }
        for (int i = 1; i <= maxV; ++i)
        {
            if (arr[i] > 0)
            {
                for (long long j = 1; j * i <= maxV; ++j)
                {

                    ret = (ret + (sum[(j + 1) * i - 1] - sum[j * i - 1]) * j * arr[i]) % MOD;
                }
            }
        }
        return ret;
    }
};

int main(){

    return 0;
}