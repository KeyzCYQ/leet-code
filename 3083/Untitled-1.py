class Solution:
    def isSubstringPresent(self, s: str) -> bool:
        sub = ""
        rev = ""
        for i in range(len(s) -1, -1, -1):
            rev += s[i] 
        for i in range(len(s) - 1):
            sub = s[i] + s[i+1]
            if rev.find(sub) > -1:
                return True
        
        return False

print(Solution().isSubstringPresent("abcd"))