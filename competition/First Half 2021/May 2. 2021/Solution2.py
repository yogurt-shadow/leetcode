class Solution(object):
    def __init__(self):
        self.s = " "
        
    def convert(self, s):
        x = 0
        for i in s:
            y = ord(i) - ord('0')
            x = 10 * x + y
        return x
    
    def split(self, index, num):
        if index >= len(self.s):
            return True
        if self.list2[index][len(self.s) - 1] == num - 1:
            return True
        for j in range(index, len(self.s)):
            x = self.list2[index][j]
            if x == num - 1 and self.split(j + 1, num - 1):
                print(num)
                return True
        return False
        
    
    def splitString(self, s):
        """
        :type s: str
        :rtype: bool
        """
        self.s = s
        self.list2 = [[0] * len(self.s) for i in range(0, len(self.s))]
        for i in range(0, len(self.s)):
            for j in range(i, len(self.s)):
                str = self.s[i:j + 1]
                self.list2[i][j] = self.convert(str)
                #print(i, j, self.list2[i][j])
        #print(0, 3, self.list2[0][3])
        for k in range(1, len(self.s)):
            num = self.list2[0][k - 1]
            #print(0, k - 1, num)
            if self.split(k, num):
                return True
        return False
        
           
        

        
        