class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        dict={}
        N,M = len(s), len(t)
        if N!=M: return False

        for i in range(N):
            dict[s[i]] = dict.get(s[i],0) + 1
            dict[t[i]] = dict.get(t[i],0) - 1

        for v in dict.values():
            if v!=0:
                return False
        return True

        