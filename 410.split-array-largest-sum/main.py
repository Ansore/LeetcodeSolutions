class Solution(object):
    def splitArray(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        if not nums:
            return 0
        if len(nums) <= k:
            return max(nums)
        low = max(nums)
        high = sum(nums)
        while low < high:
            mid = low + (high - low) // 2
            if self.check(nums, k, mid):
                high = mid
            else:
                low = mid + 1
        return low


    def check(self, nums, m, mid):
        sub_sum = 0
        for num in nums:
            if sub_sum + num > mid:
                m -= 1
                if m <= 0:
                    return False
                sub_sum = num
            else:
                sub_sum += num
        return True

if __name__ == "__main__":
    s = Solution()
    nums = [7,2,5,10,8]
    k = 2
    print(s.splitArray(nums, k))
