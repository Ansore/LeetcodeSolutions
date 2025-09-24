class Solution(object):
    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """
        v1 = version1.split(".")
        v2 = version2.split(".")
        v = v1 if len(v1) > len(v2) else v2
        for i in range(len(v)):
            t1 = 0
            t2 = 0
            if i < len(v1):
                t1 = int(v1[i])
            if i < len(v2):
                t2 = int(v2[i])
            if t1 < t2:
                return -1
            elif t1 > t2:
                return 1
        return 0
