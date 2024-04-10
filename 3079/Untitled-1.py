import math
class Solution:
    def sumOfEncryptedInt(self, nums: list[int]) -> int:
        def encrypt(x):
            large = 0
            base = 0
            
            for i in range(int(math.log10(x)), -1, -1):
                digit = int(x/(10**i))
                large = max(large, digit)
                x -= digit * (10**i)
                base += 10**i

            x = base * large

            return x
        
        sum = 0
        for x in nums:
            sum += encrypt(x)
        return int(sum)


print(Solution().sumOfEncryptedInt([10, 21, 30]))