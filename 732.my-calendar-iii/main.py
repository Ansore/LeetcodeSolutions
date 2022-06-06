from sortedcontainers import SortedDict

class MyCalendarThree(object):

    def __init__(self):
        self.d = SortedDict()

    def book(self, start, end):
        self.d[start] = self.d.setdefault(start, 0) + 1
        self.d[end] = self.d.setdefault(end, 0) - 1
        r = a = 0
        for i in self.d.values():
            a += i
            r = max(r, a)
        return r
