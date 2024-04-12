#O(n^2)
import time

class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        sol = []
        n = len(nums)
        for i in range(n):
            for j in range(i + 1, n):
                if nums[i] + nums[j] == target:
                    sol.append(i)
                    sol.append(j)
                    return sol

        return sol

tests = [
    [[2,7,11,15], 9],
    [[3,2,4], 6]
]
testcase = 1
t0 = time.time()
print(Solution().twoSum(tests[testcase][0], tests[testcase][1]))
print(f'in {(time.time() - t0) * 1000} ms')