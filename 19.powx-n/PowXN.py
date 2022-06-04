# 递归降幂

class Solution(object):
    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        if n == 0 or x == 1.0:
            return 1.0
        if x == -1.0:
            return -1.0 if n%2==1 else 1.0
        if n < 0:
            return 1 / self.myPow(x, -n)
        if n % 2 == 0:
            return self.myPow(x * x, n / 2)
        else:
            return x * self.myPow(x * x, (n - 1) / 2)

if __name__ == "__main__":
    s = Solution();
    print(s.myPow(0.00001, 21472737712))
