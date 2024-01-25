class Solution(object):
    def giveGem(self, gem, operations):
        """
        :type gem: List[int]
        :type operations: List[List[int]]
        :rtype: int
        """
        for op in operations:
            x, y = op
            gem[y] += gem[x]//2
            gem[x] -= gem[x]//2
        return max(gem) - min(gem)

if __name__ == "__main__":
    gem = [3,1,2]
    operations = [[0,2],[2,1],[2,0]]
    print(Solution().giveGem(gem, operations))
