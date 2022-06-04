#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

bool cmp(int x,int y)
{
	return x<y;
}
class Solution {
	public:
		vector<vector<int>> threeSum(vector<int>& nums) {
			vector<vector<int>> result;
			int numsSize = nums.size();
			if(numsSize < 3) {
				return result;
			}

			sort(nums.begin(),nums.end(),cmp);
			if(nums[0] > 0) {
				return result;
			}
			for(int i = 0; i < nums.size(); i ++) {

				// 双指针
				int left = i+1;
				int right = numsSize - 1;

				if(i == 0 || nums[i-1] != nums[i])
					while(left < right) {
						if(nums[left] + nums[right] + nums[i] == 0) {
							vector<int> tmp(3, 0);
							tmp[0] = nums[left];
							tmp[1] = nums[i];
							tmp[2] = nums[right];
							result.push_back(tmp);
							while(left < right && nums[left] == nums[left+1]) {
								left ++;
							}
							while(left < right && nums[right] == nums[right-1]) {
								right --;
							}
							left ++;
							right --;
						} else if(nums[left] + nums[right] + nums[i] < 0) {
							left ++;
							while(left < right && nums[left] == nums[left - 1]) {
								left ++;
							}
						} else {
							right --;
							while(right > left && nums[right] == nums[right + 1]) {
								right --;
							}
						}
					}
			}

			return result;
		}
};

int main(int argc, char *argv[])
{
	Solution s;
	//[-1,0,1,2,-1,-4]
	//vector<int> nums = {-1, 0, 1, 2, -1, -4};
	//vector<int> nums = {0, 0, 1, -1, 0, 0};
	vector<int> nums = {0, 0, 0};
	vector<vector<int>> r = s.threeSum(nums);
	for(int i = 0; i < r.size(); i ++) {
		for(int j = 0; j < r[i].size(); j ++) {
			cout << r[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
