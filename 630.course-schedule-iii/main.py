import heapq
from typing import List

class Solution:
    def scheduleCourse(self, courses: List[List[int]]) -> int:
        courses.sort(key=lambda c: c[1])

        q = list()
        # 优先队列中的总时间
        total = 0
        for ti, di in courses:
            if total + ti <= di:
                total += ti
                heapq.heappush(q, -ti)
            elif q and -q[0] > ti:
                total -= -q[0] - ti
                heapq.heappop(q)
                heapq.heappush(q, -ti)
        return len(q)
