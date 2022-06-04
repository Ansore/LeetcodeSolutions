#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		int removeDuplicates(vector<int>& nums) {
			if(nums.size() < 2) {
				return nums.size();
			}
			int start = 0;
			for(int i = 1; i < nums.size(); i ++) {
				if(nums[start] != nums[i]) {
					nums[start + 1] = nums[i];
					start ++;
				}
			}
			return start + 1;
		}
};

int main(int argc, char *argv[])
{
	vector<int> nums = {1, 1, 2};
	//vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
	Solution s;
	cout << s.removeDuplicates(nums) << endl;
	return 0;
}
