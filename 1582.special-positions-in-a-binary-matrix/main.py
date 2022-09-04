class Solution(object):
    def getRowsSum(self, mat, row):
        return sum(mat[row])
    def getColumnSum(self, mat, column):
        return sum((zip(*mat))[column])
    def numSpecial(self, mat):
        """
        :type mat: List[List[int]]
        :rtype: int
        """
        res = 0
        for i in range(len(mat)):
            for j in range(len(mat[i])):
                if mat[i][j] == 1 and self.getRowsSum(mat, i) == 1 and self.getColumnSum(mat, j) == 1:
                    res += 1
        return res
