#only works on leetcode.com
import time

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        sol = 0

        def sum(node, isLeft):
            if not node.left and not node.right and isLeft:
                return node.val
            else:
                return (sum(node.left, 1) if node.left else 0) + (sum(node.right, 0) if node.right else 0)

        return sum(root, 0)

tests = [

]
testcase = 0
t0 = time.time()
print()
print(f'in {(time.time() - t0) * 1000} ms')