#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

		int res = 0;

		for (int i = 0; i < nums.size(); i++) {
			int temp = 0;
			for(int j = i; j < nums.size(); j ++) {
				temp += nums[j];
				if(temp == k) {
					res ++;
				}
			}
		}

		return res;
    }
};

int main(int argc, char *argv[])
{
	vector<int> nums = {1,1,1, 2};
	int k = 2;
	Solution s;
	cout << s.subarraySum(nums, k) << endl;
	return 0;
}
