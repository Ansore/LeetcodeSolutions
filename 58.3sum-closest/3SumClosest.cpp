#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
	public:
		int threeSumClosest(vector<int>& nums, int target) {
			if(nums.size() < 3) {
				return 0;
			}
			sort(nums.begin(), nums.end());
			int res = nums[0] + nums[1] + nums[2];
			for(int i = 0; i < nums.size(); i ++) {
				// 双指针
				int left = i + 1;
				int right = nums.size()-1;

				while(left < right) {
					int temp = nums[left] + nums[i] + nums[right];
					if(abs(target - temp) < abs(target - res)) {
						res = temp;
					}
					if(temp < target) {
						left ++;
					} else if(temp > target) {
						right --;
					} else {
						return res;
					}
				}
			}
			return res;
		}
};

int main(int argc, char *argv[])
{
	Solution s;
	vector<int> nums = {0, 2, 1, -3};
	cout << s.threeSumClosest(nums, 1) << endl;
	return 0;
}
