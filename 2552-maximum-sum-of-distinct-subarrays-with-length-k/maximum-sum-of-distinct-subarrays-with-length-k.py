class Solution:
    def maximumSubarraySum(self, nums: List[int], k: int) -> int:
        ms=0
        cs=0
        window_set=set()
        start=0
        for end in range(len(nums)):
            while nums[end] in window_set or end-start+1>k:
                window_set.remove(nums[start])
                cs-=nums[start]
                start+=1
            window_set.add(nums[end])
            cs+=nums[end]
            if end-start+1==k:
                ms=max(ms,cs)
        return ms
        