class Solution:
    def timeRequiredToBuy(self, tickets: list[int], k: int) -> int:
        time = 0
        for i in range(len(tickets)):
            if tickets[i] < tickets[k]:
                time += tickets[i]
            elif tickets[i] >= tickets[k]:
                if i > k:
                    time += tickets[k] - 1
                elif i <= k:
                    time += tickets[k]
        
        return time


tests = [
    [[2,3,2], 2],
    [[84,49,5,24,70,77,87,8], 3],
    ]
testcase = 1
print(Solution().timeRequiredToBuy(tests[testcase][0], tests[testcase][1]))
                