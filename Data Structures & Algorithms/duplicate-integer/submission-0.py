class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        dict={}
        for n in nums:
            if dict.get(n,0) == True:
                return True
            dict[n] = True
        return False
