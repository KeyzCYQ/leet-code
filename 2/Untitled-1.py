import time
class ListNode:
     def __init__(self, val=0, next=None):
         self.val = val
         self.next = next
         
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        sol = None
        a = 0
        x = ListNode()
        sol = x
        while l1 or l2:
            n1 = l1.val if l1 else 0
            n2 = l2.val if l2 else 0
            x.val = (n1 + n2 + a)%10
            a = int((n1 + n2 + a)/10)
            if (l1 and l1.next) or (l2 and l2.next) or a:
                x.next = ListNode(a) 
                x = x.next
            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None
        

        return sol
        

tests = [
    [[2,4,3], [5,6,4]]
]
testcase = 0
t0 = time.time()
print(Solution().addTwoNumbers(tests[testcase][0], tests[testcase][1]))
print(f'in {(time.time() - t0) * 1000} ms')