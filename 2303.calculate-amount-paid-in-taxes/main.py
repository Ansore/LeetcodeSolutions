class Solution(object):
    def calculateTax(self, brackets, income):
        """
        :type brackets: List[List[int]]
        :type income: int
        :rtype: float
        """
        tax = 0
        sa = income
        for i in range(0, len(brackets)):
            if sa <= brackets[i][0]:
                if i == 0:
                    tax += sa * (brackets[i][1] / 100.0)
                else:
                    tax += (sa - brackets[i - 1][0]) * (brackets[i][1] / 100.0)
                return tax
            else:
                if i == 0:
                    tax += brackets[i][0] * (brackets[i][1] / 100.0)
                else:
                    tax += (brackets[i][0] - brackets[i-1][0]) * (brackets[i][1] / 100.0)
        return tax
if __name__ == "__main__":
    s = Solution()
    print(s.calculateTax([[3,50],[7,10],[12,25]], 10))
    print(s.calculateTax([[3,50],[7,10],[12,25]], 0))
