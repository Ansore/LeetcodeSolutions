#include <iostream>
#include <vector>

using namespace std;

// 子数组最大值是有范围的，即[max(nums), sum(nums)]之中
// 令l = max(nums), h = sum(nums), mid = (l+h)/2
// 计算数组和最大值不大于mid对应的子数组个数cnt
// 如果cnt>m,说明划分的子数组多了，及mid偏小，故l = mid+1
// 否则说明子数组划分少了，即mid偏大，故h=mid
class Solution {
	public:
		int splitArray(vector<int>& nums, int m) {
			long l = nums[0], h = 0;
			for(auto i : nums) {
				h += i;
				l = l>i?l:i;
			}
			while(l < h) {
				long mid = (l+h)/2;
				long temp = 0;
				int cnt = 1;
				for(auto i : nums) {
					temp += i;
					if(temp > mid) {
						temp = i;
						cnt ++;
					}
				}
				if(cnt > m) {
					l = mid + 1;
				} else {
					h = mid;
				}
			}
			return l;
		}
};

int main(int argc, char *argv[])
{
	vector<int> nums = {7, 2, 5, 10, 8};
	Solution s;
	cout << s.splitArray(nums, 2) << endl;
	return 0;
}
