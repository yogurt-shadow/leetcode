MOD = 1000000007

class Solution3:
    def minNonZeroProduct(self, p: int) -> int:
        if p == 1:
            return 1
        h = pow(2, p)
        return pow(h - 2, h // 2 - 1, MOD) * (h - 1) % MOD

s = Solution3()
print(s.minNonZeroProduct(30))