class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution662:
    def widthOfBinaryTree(self, root: TreeNode) -> int:
        ans = 0
        if not root:
            return 0
        q = [(root, 0, 1)]
        while q:
            size = len(q)
            x, y = -1, -1
            for i in range(size):
                a, b, c = q.pop(0)
                if a.left:
                    q.append((a.left, b + 1, c * 2))
                    if x == -1:
                        x = c * 2
                    y = c * 2
                if a.right:
                    q.append((a.right, b + 1, c * 2 + 1))
                    if x == -1:
                        x = c * 2 + 1
                    y = c * 2 + 1
            ans = max(ans, y - x + 1)
        return ans
