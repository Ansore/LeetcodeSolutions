#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
		int n = nums.size();
		if(n == 0) {
			return 0;
		}
		int ans = INT_MAX;
		int start = 0, end = 0;
		int sum = 0;
		while(end < n) {
			sum += nums[end];
			while(sum >= s) {
				ans = min(ans, end-start + 1);
				sum -= nums[start];
				start ++;
			}
			end ++;
		}
		return ans==INT_MAX ? 0 : ans;
    }
};

int main(int argc, char *argv[])
{
	vector<int> nums = {2, 3, 1, 2, 4, 3};
	int s = 7;
	Solution solution;
	cout << solution.minSubArrayLen(s, nums) << endl;
	return 0;
}
