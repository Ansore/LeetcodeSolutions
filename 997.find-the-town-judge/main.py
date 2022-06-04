from typing import List

class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        others = list(map(lambda x : x[0], trust))
        trusted = list(map(lambda x : x[1], trust))
        a = [0 for _ in range(0,n+1)]
        for i in trusted:
            a[i] += 1
        for i in range(1, len(a)):
            if a[i] == n-1 and i not in others:
                return i
        return -1

if __name__ == '__main__':
    s = Solution()
    n = 4
    trust = [[1,3],[1,4],[2,3],[2,4],[4,3]]
    # print(list(map(lambda x : x[0], trust)))
    # n = 3
    # trust = [[1,2],[2,3]]
    print(s.findJudge(n, trust))
