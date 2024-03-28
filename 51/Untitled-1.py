class Solution:
    def solveNQueens(self, n: int) -> list[list[str]]:
        M = [("." * n) for _ in range(n)]
        Q = [(-1, -1) for _ in range(n)]
        sol = []

        def change_letter(string: str, index, new_letter):
            return string[:index] + new_letter + string[index + 1:]
        
        def isValid(q) -> bool:
            for i in range(n - 1):
                if q[i][0] != -1:
                    for j in range(i + 1, n):
                        if q[j][0] != -1 and (q[i][0] == q[j][0] or q[i][1] == q[j][1] or (abs(q[i][0] - q[j][0]) == abs(q[i][1] - q[j][1]))):
                            return False
            return True

        def brute(q, i):
            if i == n:
                if isValid(q):
                    temp_M = [m for m in M]
                    for a in q:
                        temp_M[a[0]] = change_letter(M[a[0]], a[1], "Q")
                    
                    sol.append(temp_M)
            else:
                for j in range(n):
                    q[i] = (i, j)
                    if isValid(q):
                        brute(q, i + 1)
                q[i] = (-1, -1)
        
        temp_q = [q for q in Q]
        brute(temp_q, 0)

        return sol


tests = [1, 2, 3, 4, 5]
testcase = 4
print(Solution().solveNQueens(tests[testcase]))