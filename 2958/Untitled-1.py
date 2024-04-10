#time limit exceeded

import time

class Solution:
    def maxSubarrayLength(self, nums: list[int], k: int) -> int:
        for n in range(len(nums), 0, -1):
            for i in range(len(nums) - n + 1):
                a = dict()
                b = True
                for j in range(i, i + n):
                    if nums[j] in a.keys():
                        a[nums[j]] += 1
                    else:
                        a[nums[j]] = 1
                    if a[nums[j]] > k:
                        b = False
                        break
                
                if b:
                    return n

tests = [
    [[1,2,3,1,2,3,1,2], 2],
    [[3,1,1], 1]
]
testcase = 1
t0 = time.time()
print(Solution().maxSubarrayLength(tests[testcase][0], tests[testcase][1]))
print(f"in {(time.time() - t0) * 1000} ms")