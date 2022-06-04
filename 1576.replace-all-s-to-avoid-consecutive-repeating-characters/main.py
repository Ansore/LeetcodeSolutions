class Solution:
    def modifyString(self, s):
        s = list(s)
        for i in range(len(s)):
            if s[i] == '?':
                for c in "abc":
                     if not (i > 0 and s[i-1]==c or i < len(s)-1 and s[i+1]==c):
                        s[i] = c
                        break
        return "".join(s)

if __name__ == "__main__":
    s = Solution()
