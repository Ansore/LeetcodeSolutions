class Solution(object):
    def alternatingSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) < 2:
            return -1
        ret = -1
        tmp = 1
        flag = 1
        for i in range(0, len(nums)):
            for j in range(i+1, len(nums)):
                if nums[j] - nums[j-1] == flag:
                    tmp += 1
                    flag = -flag
                    if j == len(nums)-1:
                        if tmp > ret and tmp != -1:
                            ret = tmp
                        tmp = 1
                        flag = 1
                        break
                else:
                    if tmp > ret and tmp != 1:
                        ret = tmp
                    tmp = 1
                    flag = 1
                    break
        return ret

if __name__ == "__main__":
    nums = [2,3,4,3,4]
    print(Solution().alternatingSubarray(nums))
