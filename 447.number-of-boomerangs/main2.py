from collections import defaultdict


class Solution(object):
    def numberOfBoomerangs(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        res = 0
        for p1 in points:
            cnt = defaultdict(int)
            for p2 in points:
                dist = (p1[0]-p2[0])**2 + (p1[1]-p2[1])**2
                cnt[dist] += 1
            for m in cnt.values():
                res += m*(m-1)
        return res




if __name__ == "__main__":
    s = Solution()
    points = [[0,0],[1,0],[2,0]]
    print(s.numberOfBoomerangs(points))
