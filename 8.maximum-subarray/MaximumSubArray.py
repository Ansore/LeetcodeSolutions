def maxSubArray(nums):
    if len(nums) == 0:
        return 0
    result = nums[0]
    sum = 0
    for num in nums:
        if(sum < 0):
            sum = num
        else:
            sum += num
        result = max(result, sum)
    return result

if __name__ == "__main__":
    nums = [1, 2, 3, 4, 5]
    print(maxSubArray(nums))
