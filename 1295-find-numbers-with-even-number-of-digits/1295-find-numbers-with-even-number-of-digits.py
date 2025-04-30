class Solution(object):
    def findNumbers(self, nums):
        n=len(nums)
        c=0
        for i in nums:
            j=str(i)
            if len(j) % 2 == 0:
                c=c+1
        return c

        """
        :type nums: List[int]
        :rtype: int
        """
        