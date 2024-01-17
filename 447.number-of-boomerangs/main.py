class Solution(object):
    def numberOfBoomerangs(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        count = 0
        for i in range(0, len(points)):
            for j in range(0, len(points)):
                for k in range(0, len(points)):
                    if i == j or j == k or k == i:
                        continue
                    if (((points[i][0]-points[j][0])**2 + (points[i][1]-points[j][1])**2) == 
                            ((points[i][0]-points[k][0])**2 + (points[i][1]-points[k][1])**2)):
                        count += 1
        return count



if __name__ == "__main__":
    s = Solution()
    points = [[0,0],[1,0],[2,0]]
    print(s.numberOfBoomerangs(points))
