class Solution5677(object):
    def countHomogenous(self, s):
        """
        :type s: str
        :rtype: int
        """
        array = []
        cur = '+'
        number = 0
        for i in range(len(s)):
            cur2 = s[i]
            if cur2 == cur:
                number += 1
            else:
                array.append(number)
                number = 1
                cur = cur2
        array.append(number)
        count = 0
        x = 1000000007
        for i in range(len(array)):
            mm = array[i]
            count += mm * (mm + 1) / 2
        return count % x

s = Solution5677()
print(s.countHomogenous("abbcccaa"))
