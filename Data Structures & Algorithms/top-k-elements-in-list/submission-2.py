import heapq

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        dict={}

        for n in nums:
            dict[n] = dict.get(n, 0) + 1
        heap=[]

        for n,freq in dict.items():
            heapq.heappush(heap, (freq,n))

            if len(heap)>k:
                heapq.heappop(heap)
        
        return [p[1] for p in heap]



        