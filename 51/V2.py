class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        #1) solve n = 4
        #2) store all possible k solutions with k = (4, n)
        #3) k-th solution 

tests = [1, 2, 3, 4, 5]
testcase = 4
print(Solution().solveNQueens(tests[testcase]))