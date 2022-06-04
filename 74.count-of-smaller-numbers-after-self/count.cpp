#include <iostream>
#include <vector>

using namespace std;

class Solution {
	public:
		vector<int> countSmaller(vector<int>& nums) {
			if(nums.empty()) {
				return {};
			}
			vector<int> count(nums.size(), 0);
			for(int i=0; i < nums.size()-1; i ++) {
				int temp = 0;
				for(int j=i+1; j < nums.size(); j ++) {
					if(nums[j] < nums[i]) {
						temp ++;
					}
				}
				count[i] = temp;
			}
			return count;
		}
};

int main(int argc, char *argv[])
{
	vector<int> nums = {5,2,6,1};
	Solution s;

	vector<int> res = s.countSmaller(nums);
	for(int i=0; i < res.size(); i ++) {
		cout << res[i] << " ";
	}
	cout << endl;
	return 0;
}
