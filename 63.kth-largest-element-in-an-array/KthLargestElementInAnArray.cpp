#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
			sort(nums.begin(), nums.end());
			return nums[nums.size()-k];
    }
};

int main(int argc, char *argv[])
{
	vector<int> nums = {3, 2, 1, 5, 6, 4};
	Solution s;
	cout << s.findKthLargest(nums, 2) << endl;
	return 0;
}
