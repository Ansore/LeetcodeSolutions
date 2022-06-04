#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		int getMaxIndexInRange(vector<int>& nums, int start, int step) {

			if(start + step >= nums.size() - 1) {
				return nums.size();
			}

			int maxIndex = start;
			int oSum = start + nums[start];

			for(int i = start+1; i < start+step+1; i ++) {
				if(i+nums[i] > maxIndex+nums[maxIndex] && nums[i] != 0) {
					maxIndex = i;
				}
			}
			cout << "==" << maxIndex << endl;
			return maxIndex;
		}

		int jump(vector<int>& nums) {

			if(nums.size() <= 1) {
				return 0;
			}

			int currentIndex = 0;
			int count = 0;

			while(currentIndex < nums.size() - 1) {
				currentIndex = getMaxIndexInRange(nums, currentIndex, nums[currentIndex]);
				cout << "---" << nums[currentIndex] << endl;
				count ++;
			}
			return count;
		}
};

int main(int argc, char *argv[])
{
	//vector<int> nums = {2,3,1,1,1, 2, 1, 1, 1,1, 1};
	//vector<int> nums = {5,9,3,2,1,0,2,3,3,1,0,0};
	//vector<int> nums = {4,1,1,3,1,1,1};
	//vector<int> nums = {10,9,8,7,6,5,4,3,2,1,1,0};
	//vector<int> nums = {7,0,9,6,9,6,1,7,9,0,1,2,9,0,3};
	//vector<int> nums = {9,8,2,2,0,2,2,0,4,1,5,7,9,6,6,0,6,5,0,5};
	//vector<int> nums = {2,3,1,1,4};
	vector<int> nums = {8,2,4,4,4,9,5,2,5,8,8,0,8,6,9,1,1,6,3,5,1,2,6,6,0,4,8,6,0,3,2,8,7,6,5,1,7,0,3,4,8,3,5,9,0,4,0,1,0,5,9,2,0,7,0,2,1,0,8,2,5,1,2,3,9,7,4,7,0,0,1,8,5,6,7,5,1,9,9,3,5,0,7,5};
	//vector<int> nums = {2,0,8,0,3,4,7,5,6,1,0,0,5,9,7,5,3,6};

	Solution s;
	cout << s.jump(nums) << endl;
	return 0;
}
