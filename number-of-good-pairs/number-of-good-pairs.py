class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        st = set(nums)
        sum = 0
        for x in st:
            val = nums.count(x)
            sum+=(val*(val-1))/2
        return int(sum)