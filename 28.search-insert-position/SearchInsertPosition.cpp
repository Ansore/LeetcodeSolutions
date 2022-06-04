#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			if(nums[i] == target) {
				return i;
			}
			if(nums[i] > target) {
				nums.insert(nums.begin() + i, target);
				return i;
			}
		}
		// 如果taget比前面都大
		nums.insert(nums.end(), target);
		return n;
    }
};

int main(int argc, char *argv[])
{
	vector<int> nums = {1, 3, 5, 6};
	int target = 0;
	Solution s;
	cout << s.searchInsert(nums, target) << endl;;
	return 0;
}
