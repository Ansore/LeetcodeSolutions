class Solution(object):

    def f(self, w):
        c = min(w)
        return w.count(c)

    def numSmallerByFrequency(self, queries, words):
        """
        :type queries: List[str]
        :type words: List[str]
        :rtype: List[int]
        """
        answer = [0 for _ in range(len(queries))]
        wl = [self.f(w) for w in words]
        wl.sort()
        for i, q in enumerate(queries):
            t = self.f(q)
            for w in wl:
                if t < w:
                    answer[i] += 1
                else:
                    continue

        return answer


if __name__ == "__main__":
    s = Solution()
    # queries = ["cbd"]
    # words = ["zaaaz"]
    queries = ["bbb","cc"]
    words = ["a","aaa","aa","aaaa"]
    print(s.numSmallerByFrequency(queries, words))
