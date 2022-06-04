
class MaximumSubArray {

	public int maxSubArray(int[] nums) {
		if(nums.length == 0) {
			return 0;
		}
		int result = nums[0];
		int sum = 0;
		for (int num: nums) {
			if(sum < 0) {
				sum = num;
			} else {
				sum += num;
			}
			result = Math.max(result, sum);
		}
		return result;
	}

	public static void main(String[] args) {
		int[] nums = {1, -2,2,3, -1,4};
		System.out.println(new MaximumSubArray().maxSubArray(nums));
	}
}
