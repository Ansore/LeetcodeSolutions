class Solution(object):
    def isAcronym(self, words, s):
        """
        :type words: List[str]
        :type s: str
        :rtype: bool
        """
        if (len(words) != len(s)):
            return False
        for i, w in enumerate(words):
            if (i >= len(s)):
                return False
            if w[0] != s[i]:
                return False
        return True


if __name__ == "__main__":
    print(Solution().isAcronym(["alice","bob","charlie"], "abc"))
