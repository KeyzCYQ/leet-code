#Input: deck = [17,13,11,2,3,5,7]
#Output: [2,13,3,11,5,17,7]
import time
class Node:
    def __init__(self, Value):
        self.Value : int = Value
        self.Next : Node = None

class Q:
    def __init__(self):
        self.Head : Node = None
    
    def push(self, Value: int):
        if not self.Head:
            self.Head = Node(Value)
            return
        x : Node = self.Head
        self.Head = Node(Value)
        self.Head.Next = x

    def pop(self) -> int:
        if not self.Head.Next:
            x = self.Head.Value
            self.Head = None
            return x
        x : Node = self.Head
        while x.Next.Next:
            x = x.Next
        y = x.Next.Value
        x.Next = None
        return y

    def toArray(self):
        arr = []
        x = self.Head
        while x:
            arr.append(x.Value)
            x = x.Next

        return arr

class Solution:
    def deckRevealedIncreasing(self, deck: list[int]) -> list[int]:
        n = len(deck)
        q = Q()

        deck.sort(reverse=True)
        q.push(deck[0])
        for i in range(1, n):
            x = q.pop()
            q.push(x)
            q.push(deck[i])


        return q.toArray()

tests = [
    [17,13,11,2,3,5,7],
    [17,13,11,2,3,5,7,19],
    [1,2,3],
    [1,2,3,4],
    [1,2,3,4,5],
    [1,2,3,4,5,6],
    [1,2,3,4,5,6,7,8,9]
]
testcase = 5
t0 = time.time()
print(Solution().deckRevealedIncreasing(tests[testcase]))
print(f'in {(time.time() - t0) * 1000} ms')