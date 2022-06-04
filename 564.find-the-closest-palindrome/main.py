class Solution(object):
    def nearestPalindromic(self, n):
        """
        :type n: str
        :rtype: str
        """
        if len(n) == 1:
            return str(int(n)-1)

        cond = [10**(len(n)-1)-1, 10**(len(n)-1)+1]

        me = int(n)
        m = len(n)
        if m % 2 == 0:
            z = int(n[:m//2])
            x = z-1
            y = x
            while x:
                y = y * 10 + x % 10
                x //= 10
            cond.append(y)
            x = z+1
            y = x
            while x:
                y = y * 10 + x % 10
                x //= 10
            cond.append(y)
        else:
            z = int(n[:m//2+1])
            x = z-1
            y = x
            x //= 10
            while x:
                y = y * 10 + x % 10
                x //= 10
            cond.append(y)
            x = z+1
            y = x
            x //= 10
            while x:
                y = y * 10 + x % 10
                x //= 10
            cond.append(y)
        print(cond)
        ret = cond[0]
        minNum = abs(ret - me)
        for i in range(1, len(cond)):
            tmp = abs(cond[i] - me)
            if minNum > tmp and tmp != 0:
                ret = cond[i]
                minNum = tmp
            elif minNum == tmp:
                ret = min(ret, cond[i])
        return str(ret)




if __name__ == "__main__":
    s = Solution()
    print(s.nearestPalindromic("123"))
