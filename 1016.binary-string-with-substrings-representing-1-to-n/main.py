# class Solution(object):
#     def queryString(self, s, n):
#         """
#         :type s: str
#         :type n: int
#         :rtype: bool
#         """
#         for i in range(1, n+1):
#             if bin(i)[2:] not in s:
#                 return False
#         return True


class Solution:
    def queryString(self, s: str, n: int) -> bool:
        for i in range(1, n+1):
            if bin(i)[2:] not in s:
                return False
        return True
        # return all(bin(i)[2:] in s for i in range(1, n + 1))
if __name__ == "__main__":
    s = Solution()
    print(s.queryString("011010101010111101010101011111111111111111111111111111111110000000000000011111101010101001010101010101010101010101111010101010111111111111111111111111111111111100000000000000111111010101010010101010101010101010100", 1000000000))
