#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		int maxSubArray(vector<int>& nums) {
			if(nums.size() == 0) {
				return NULL;
			}
			int result = nums[0];
			int sum = 0;
			for(int i = 0; i < nums.size(); i ++) {
				if(sum < 0) {
					sum = nums[i];
				} else {
					sum = sum + nums[i];
				}
				result = max(result, sum);
			}
			return result;
		}
};

int main(int argc, char *argv[])
{
	vector<int> a = {-2,1,-3,4,-1,2,1,-5,4};
	Solution s;
	cout << s.maxSubArray(a) << endl;;
	return 0;
}
