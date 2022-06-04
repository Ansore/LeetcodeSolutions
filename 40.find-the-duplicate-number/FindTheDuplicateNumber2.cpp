#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		int findDuplicate(vector<int>& nums) {
			int res = 0;
			int n = nums.size();
			int left = 0, right = n-1;
			while(left <= right) {
				//mid = (right-left) / 2 + left;
				int mid = (right + left) >> 1;
				int count = 0;
				for(int i = 0; i < n; i ++) {
					if(nums[i] <= mid) {
						count ++;
					}
				}
				if(count <= mid) {
					left = mid + 1;
				} else {
					right = mid - 1;
					res = mid;
				}
			}
			return res;
		}
};

int main(int argc, char *argv[])
{
	Solution s;
	vector<int> nums = {1, 3, 4, 2, 2};
	cout << s.findDuplicate(nums) << endl;
	return 0;
}
