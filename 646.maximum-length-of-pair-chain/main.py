class Solution(object):
    def findLongestChain(self, pairs):
        """
        :type pairs: List[List[int]]
        :rtype: int
        """
        res = 1;
        pairs = sorted(pairs, key=lambda x : x[1])
        tmp = pairs[0][1]
        for i in range(len(pairs)):
            if (pairs[i][0] > tmp):
                res += 1
                tmp = pairs[i][1]

        return res
