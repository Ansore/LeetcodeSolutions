# 二分法
class Solution(object):
    def minEatingSpeed(self, piles, h):
        right = max(piles)
        left = 1
        while left < right:
            mid = (left + right) / 2
            times = 0
            for i in piles:
                times += ((i-1)/mid) + 1
            if times > h:
                left = mid + 1
            else:
                right = mid
        return right
