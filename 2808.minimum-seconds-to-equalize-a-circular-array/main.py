class Solution(object):
    def minimumSeconds(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        res = n = len(nums)
        mp = defaultdict(list)
        for i, a in enumerate(nums):
            mp[a].append(i)
        for pos in mp.values():
            mx = pos[0] + n - pos[-1]
            for i in range(len(pos)):
                mx = max(mx, pos[i] - pos[i-1])
            res = min(res, mx // 2)
        return res

