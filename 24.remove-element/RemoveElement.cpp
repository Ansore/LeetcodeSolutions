#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		int removeElement(vector<int>& nums, int val) {
			if(nums.size() == 0) {
				return 0;
			}
			int start = 0;
			for(int i= 0; i < nums.size(); i ++) {
				if(nums[i] != val) {
					cout << i;
					if(start != i)
						nums[start] = nums[i];
					start ++;
				}
			}
			cout << "-----" << endl;
			for(int j = 0; j < nums.size(); j ++) {
				cout << nums[j] << " ";
			}
			cout << endl;
			return start;
		}
};

int main(int argc, char *argv[])
{
	//vector<int> nums = {3, 2, 2, 3};
	vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
	int val = 2;
	Solution s;
	cout << s.removeElement(nums, val) << endl;
	return 0;
}
