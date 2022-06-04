#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		vector<int> twoSum(vector<int>& nums, int target) {
			vector<int> result;
			result.push_back(0);
			result.push_back(0);

			for(int i = 0; i < nums.size(); i ++) {
				result[0] = i;
				int temp = target - nums[i];
				for(int j = 0; j < nums.size(); j ++) {
					if(j != i && temp == nums[j]) {
						result[1] = j;
						return result;
					}
				}
			}
			result[0] = 0;
			result[1] = 0;
			return result;
		}
};

int main(int argc, char *argv[])
{
	Solution s;

	//vector<int> nums = {2, 7, 11, 15};
	vector<int> nums;
	nums.push_back(-1);
	nums.push_back(-2);
	nums.push_back(-3);
	nums.push_back(-4);
	nums.push_back(-5);
	//nums.push_back(15);

	int target = -8;

	vector<int> result = s.twoSum(nums, target);
	for(int i = 0; i < result.size(); i ++) {
		cout << result[i] << "  " << endl;
	}
	return 0;
}
