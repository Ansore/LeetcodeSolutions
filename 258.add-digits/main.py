class Solution(object):
    def addDigits(self, num):
        """
        :type num: int
        :rtype: int
        """
        while num > 9:
            t = num % 10
            num //= 10
            num += t
        return num

if __name__ == "__main__":
    s = Solution()
    print(s.addDigits(125))
