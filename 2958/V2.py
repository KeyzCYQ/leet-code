import time
class Solution:
    def maxSubarrayLength(self, nums: list[int], k: int) -> int:
        res = 0

        a = dict()
        b = 0
        for i in range(len(nums)):
            if len(nums) - i < res:
                break
            for j in range(b, len(nums)):
                if nums[j] in a.keys():
                    a[nums[j]] += 1
                else:
                    a[nums[j]] = 1
                if a[nums[j]] <= k:
                    res = max(res, j - i + 1)
                    b = j + 1
                else:
                    a[nums[j]] -= 1
                    break
            a[nums[i]] -= 1

        return res
        

tests = [
    [[1,2,3,1,2,3,1,4], 2],
    [[3,1,1], 1],
    [[1], 1],
    [[2, 2, 3], 1],
    [[2,2,2,3], 1],
    [[1,1,1,3], 2]
]
testcase = 4
t0 = time.time()
print(Solution().maxSubarrayLength(tests[testcase][0], tests[testcase][1]))
print(f"in {(time.time() - t0) * 1000} ms")