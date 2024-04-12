#O(n)
import time

class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        sol = []
        n = len(nums)
        for i in range(n):
            j = i
            try:
                j = nums.index(target - nums[i], i + 1)
                if target - nums[i] in nums:
                    sol.append(i)
                    sol.append(j)
            except ValueError:
                a = 0

        return sol

tests = [
    [[2,7,11,15], 9],
    [[3,2,4], 6]
]
testcase = 0
t0 = time.time()
print(Solution().twoSum(tests[testcase][0], tests[testcase][1]))
print(f'in {(time.time() - t0) * 1000} ms')