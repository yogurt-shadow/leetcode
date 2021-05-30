from typing import List

class Solution5667:
    def canEat(self, candiesCount: List[int], queries: List[List[int]]) -> List[bool]:
        dict = {}
        result = []
        sum = 0
        for i in range(len(candiesCount)):
            dict[i] = sum
            sum += candiesCount[i]

        for j in range(len(queries)):
            type = queries[j][0]
            day = queries[j][1]
            maxxx = queries[j][2]
            if day < dict[type] + candiesCount[type] and maxxx * day + maxxx > dict[type]:
                result.append(True)
            else:
                result.append(False)
        return result

s = Solution5667()
candiesCount = [7,4,5,3,8]
queries = [[0,2,2],[4,2,4],[2,13,1000000000]]
result = s.canEat(candiesCount, queries)
for x in result:
    print(x)

print()

candiesCount2 = [5,2,6,4,1]
queries2 = [[3,1,2],[4,10,3],[3,10,100],[4,100,30],[1,3,1]]
for i in s.canEat(candiesCount2, queries2):
    print(i)
