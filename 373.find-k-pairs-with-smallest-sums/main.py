class Solution(object):
    def kSmallestPairs(self, nums1, nums2, k):
        result = []
        t = 0
        for i in range(0,len(nums1)):
            for j in range(0, nums2):
                if t < k:
                    result.append([i, j])
                    t += 1
                else:
                    return result
        return result


if __name__ == "__main__":
    s = Solution()
    nums1 = [1,7,11]
    nums2 = [2,4,6]
    k = 3
    print(s.kSmallestPairs(nums1, nums2, k))
