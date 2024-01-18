class Solution(object):
    def strongPasswordCheckerII(self, password):
        """
        :type password: str
        :rtype: bool
        """
        if len(password) < 8:
            return False
        tag = 0
        for i, s in enumerate(password):
            if i > 0 and password[i] == password[i-1]:
                return False
            if tag & 0b1111 == 0b1111:
                continue
            if s.islower():
                tag = tag | 0b0001
            elif s.isupper():
                tag = tag | 0b0010
            elif s.isdigit():
                tag = tag | 0b0100
            elif s in "!@#$%^&*()-+":
                tag = tag | 0b1000
        if tag & 0b1111 == 0b1111:
            return True
        return False

if __name__ == "__main__":
    s = Solution()
    # print(s.strongPasswordCheckerII("IloveLe3tcode!"))
    # print(s.strongPasswordCheckerII("IloveLetcode!"))
    # print(s.strongPasswordCheckerII("11A!A!Aa"))
    print(s.strongPasswordCheckerII("aA0!bB1@@3rbHkB8Puvl"))
