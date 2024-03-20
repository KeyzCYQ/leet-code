class Solution:
    def maxNiceDivisors(self, primeFactors: int) -> int:
        pfs = [2, 2, 3, 3, 5, 7, 11 ,11] #* primeFactors
        primeFactors = len(pfs)
        nfs = []
        
        base = 1 * pfs[0]
        mask = 1
        maskBin = 1
        old = pfs[0]
        for i in range(1, primeFactors):
            if pfs[i] != old:
                mask = mask | (1<<i)
                maskBin += 10**i
                base *= pfs[i]
                old = pfs[i]
        nfs.append(base)
        for i in range(1, primeFactors):
            if mask & (1<<i) == 0:
                base *= pfs[i]
                nfs.append(base)
        a = 0

inputs = [5, 8]
testcase = 0
Solution().maxNiceDivisors(inputs[testcase])