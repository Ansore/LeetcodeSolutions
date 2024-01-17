class Solution(object):
    def minimumRemoval(self, beans):
        """
        :type beans: List[int]
        :rtype: int
        """
        beans.sort()
        total = sum(beans)
        n = len(beans)
        res = total
        for i, b in enumerate(beans):
            tmp = total - b*(n-i)
            if tmp < res:
                res = tmp
        return res


if __name__ == "__main__":
    s = Solution()
    beans = [4,1,6,5]
    print(s.minimumRemoval(beans))
