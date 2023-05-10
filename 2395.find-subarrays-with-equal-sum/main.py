class Solution(object):
    def findSubarrays(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        s = set()
        for i in range(len(nums) - 1):
            t = nums[i] + nums[i+1]
            if t not in s:
                s.add(t)
            else:
                return True
        return False



if __name__ == "__main__":
    s = Solution()
