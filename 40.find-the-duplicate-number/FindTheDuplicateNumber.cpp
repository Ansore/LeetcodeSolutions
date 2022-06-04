#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		int findDuplicate(vector<int>& nums) {
			for(int i = 0; i < nums.size(); i ++) {
				for(int j = i+1; j < nums.size(); j ++) {
					if((nums[i] ^ nums[j]) == 0) {
						return nums[i];
					}
				}
			}
			return -1;
		}
};

int main(int argc, char *argv[])
{
	Solution s;
	vector<int> nums = {1, 3, 4, 2, 2};
	cout << s.findDuplicate(nums) << endl;
	return 0;
}
