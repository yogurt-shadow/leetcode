#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <random>


using namespace std;
typedef vector<pair<int, int>> vii;

typedef pair<int, int> pii;

class Solution4
{
private:
    // 根据正文部分的分析，我们选择的 mod 需要远大于 10^10
    // 所以 C++ 语言中我们需要用到 long long 类型
    // 那么在进行哈希值的运算时，中间值会超出 long long 类型的上限，而没有更大的类型了
    // 因此我们可以使用一种折中的办法：对 mod1 和 mod2 分别取模，得到一个二元组
    // 这本质上与对 mod1 * mod2 取模是一致的，这里我们选择 mod1=10^9+7，mod2=10^9+9
    // 它们都是质数，乘积约为 10^18，远大于 10^10
    static constexpr int mod1 = 1000000007;
    static constexpr int mod2 = 1000000009;

    // 由于我们得到的哈希是二元组，C++ 默认不支持将 pair 放入哈希表，我们需要自行实现哈希函数
    struct pairhash
    {
        size_t operator()(const pair<int, int> &p) const
        {
            auto fn = hash<int>();
            return (fn(p.first) << 16) ^ fn(p.second);
        }
    };

    using LL = long long;

public:
    int longestCommonSubpath(int n, vector<vector<int>> &paths)
    {
        // 本题中数组元素的范围为 [0, 10^5]
        // 因此我们在 [10^6, 10^7] 的范围内随机选取进制 base
        // 为了更减少冲突，我们可以对 mod1 和 mod2 分别选取 base1 和 base2
        mt19937 gen{random_device{}()};
        auto dis = uniform_int_distribution<int>(1e6, 1e7);
        int base1 = dis(gen);
        int base2 = dis(gen);

        int m = paths.size();
        // 确定二分查找的上下界
        int left = 1, right = min_element(paths.begin(), paths.end(), [](const auto &p1, const auto &p2)
                                          { return p1.size() < p2.size(); })
                                  ->size();
        int ans = 0;
        while (left <= right)
        {
            int len = (left + right) / 2;
            // 预处理 mult1=base1^len, mult2=base2^len
            int mult1 = 1, mult2 = 1;
            for (int i = 1; i <= len; ++i)
            {
                mult1 = (LL)mult1 * base1 % mod1;
                mult2 = (LL)mult2 * base2 % mod2;
            }

            unordered_set<pair<int, int>, pairhash> s;
            bool check = true;
            for (int i = 0; i < m; ++i)
            {
                int hash1 = 0, hash2 = 0;
                // 计算首个长度为 len 的子数组的哈希值
                for (int j = 0; j < len; ++j)
                {
                    hash1 = ((LL)hash1 * base1 + paths[i][j]) % mod1;
                    hash2 = ((LL)hash2 * base2 + paths[i][j]) % mod2;
                }

                unordered_set<pair<int, int>, pairhash> t;
                // 如果我们遍历的是第 0 个数组，或者上一个数组的哈希表中包含该二元组
                // 我们才会将二元组加入当前数组的哈希表中
                if (i == 0 || s.count({hash1, hash2}))
                {
                    t.emplace(hash1, hash2);
                }
                // 递推计算后续子数组的哈希值
                for (int j = len; j < paths[i].size(); ++j)
                {
                    hash1 = (((LL)hash1 * base1 % mod1 - (LL)paths[i][j - len] * mult1 % mod1 + paths[i][j]) % mod1 + mod1) % mod1;
                    hash2 = (((LL)hash2 * base2 % mod2 - (LL)paths[i][j - len] * mult2 % mod2 + paths[i][j]) % mod2 + mod2) % mod2;
                    if (i == 0 || s.count({hash1, hash2}))
                    {
                        t.emplace(hash1, hash2);
                    }
                }
                if (t.empty())
                {
                    check = false;
                    break;
                }
                s = move(t);
            }

            if (check)
            {
                ans = len;
                left = len + 1;
            }
            else
            {
                right = len - 1;
            }
        }
        return ans;
    }
};
