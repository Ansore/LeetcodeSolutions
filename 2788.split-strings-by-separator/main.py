class Solution(object):
    def splitWordsBySeparator(self, words, separator):
        """
        :type words: List[str]
        :type separator: str
        :rtype: List[str]
        """
        ret = []
        for w in words:
            ts = w.split(separator)
            for t in ts:
                if t != "":
                    ret.append(t)
        return ret


if __name__ == "__main__":
    s = Solution()
    words = ["one.two.three","four.five","six"]
    separator = "."
    print(s.splitWordsBySeparator(words, separator))
