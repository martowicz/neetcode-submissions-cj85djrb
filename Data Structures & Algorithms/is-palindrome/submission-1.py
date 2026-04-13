class Solution:
    def isPalindrome(self, s: str) -> bool:
        t = [c.lower() for c in s if c.isalnum()]

        N = len(t)
        i=0
        j=N-1
        while(i<j):
            if t[i]!=t[j]: return False
            i+=1
            j-=1
        return True
