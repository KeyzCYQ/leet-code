import time
class Solution:
    def deckRevealedIncreasing(self, deck: List[int]) -> List[int]:
        

tests = [
    [17,13,11,2,3,5,7]
    ]
testcase = 0
t0 = time.time()
print(Solution(tests[testcase]))
print(f'in {(time.time() - t0) * 1000} ms')