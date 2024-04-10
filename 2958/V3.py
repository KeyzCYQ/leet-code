import time
class Solution:
    def maxSubarrayLength(self, nums: list[int], k: int) -> int:
        res = 0
        a = dict()

        i, j = 0, 0
        while j < len(nums):
            a[nums[j]] = a.get(nums[j], 0) + 1
            if a[nums[j]] > k:
                a[nums[i]] -= 1
                a[nums[j]] -= 1
                i += 1
            else:
                res = max(res, j - i + 1)
                j += 1

        return res
        

tests = [
    [[1,2,3,1,2,3,1,4], 2],
    [[3,1,1], 1],
    [[1], 1],
    [[2, 2, 3], 1],
    [[2,2,2,3], 1],
    [[1,1,1,3], 2],
    [[1,4,4,3], 1]
]
testcase = 6
t0 = time.time()
print(Solution().maxSubarrayLength(tests[testcase][0], tests[testcase][1]))
print(f"in {(time.time() - t0) * 1000} ms")