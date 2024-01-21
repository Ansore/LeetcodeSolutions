class Solution(object):
    def dayOfYear(self, date):
        """
        :type date: str
        :rtype: int
        """
        # ds = date.split("-")
        # year = int(ds[0])
        # month = int(ds[1])
        # day = int(ds[2])
        months = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
        year, month, day = [int(x) for x in date.split('-')]
        # ret = 0
        if (year % 4 == 0 and year % 100 != 0) or year % 400 == 0:
            months[1] += 1
            # ret = 1
        # for i in range(0, month-1):
        #     ret += months[i]
        ret = sum(months[:month-1]) + day
        return ret

if __name__ == "__main__":
    s = Solution()
    print(s.dayOfYear("1900-05-02"))
