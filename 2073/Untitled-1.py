class Solution:
    def timeRequiredToBuy(self, tickets: list[int], k: int) -> int:
        def rec(tickets, k, time):
            for i in range(len(tickets)):
                if tickets[i] > 0:
                    tickets[i] -= 1
                    time += 1
                    if tickets[k] == 0:
                        return time
            
            return rec(tickets, k, time)
        
        return rec(tickets, k, 0)

tests = [
    [[2,3,2], 2],
    [[84,49,5,24,70,77,87,8], 3],
    ]
testcase = 1
print(Solution().timeRequiredToBuy(tests[testcase][0], tests[testcase][1]))
                