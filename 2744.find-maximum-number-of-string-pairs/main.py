class Solution(object):
    def maximumNumberOfStringPairs(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        count = 0
        for i in range(0,len(words)):
            for j in range(i+1,len(words)):
                if words[i] == words[j][::-1]:
                    count += 1

        return count;

if __name__ == "__main__":
    s = Solution()
    words = ["cd","ac","dc","ca","zz"];
    print(s.maximumNumberOfStringPairs(words))
