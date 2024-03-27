class Solution:
    def sumOfPower(self, nums: list[int], k: int) -> int:
        n = len(nums)
        dp = [0] * 2**n
        tot = 0

        for i in range(1, 2**n):
            for mask in range(1, i + 1):
                if i & mask == mask:
                    sum = 0
                    for j in range(n):
                        bit = 1<<j
                        if mask & bit != 0:
                            sum += nums[j]
                    if sum == k:
                        dp[i] += 1
            tot += dp[i]
        return tot

inputs = [
    [[1,2,3], 3],
    [[2,3,3], 5],
    [[1,2,5,6,6,7,9,9,1,7,9,9,5,7,8], 3]
    ]
testcase = 2
print(Solution().sumOfPower(inputs[testcase][0], inputs[testcase][1]))
