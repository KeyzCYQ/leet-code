class Solution:
    def minimumXORSum(self, nums1: list[int], nums2: list[int]) -> int:
        n = len(nums1)
        dp = [[float('inf')] * (1 << n) for _ in range(n + 1)]
        dp[0][0] = 0

        for i in range(n):
            for mask in range(1 << n):
                for j in range(n):
                    if mask & (1 << j) == 0:
                        dp[i + 1][mask | (1 << j)] = min(dp[i + 1][mask | (1 << j)], dp[i][mask] + (nums1[j] ^ nums2[i]))

        return dp[n][(1 << n) - 1]

inputs = [
    [[1,2], [2,3]],
    [[1,0,3], [5,3,4]],
    [[72,97,8,32,15], [63,97,57,60,83]
]
    ]
test_case = 1
print(Solution().minimumXORSum(inputs[test_case][0], inputs[test_case][1]))
